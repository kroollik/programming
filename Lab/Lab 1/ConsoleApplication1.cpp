#include <iostream>
#include <cpp_httplib/httplib.h>
#include <nlohmann/json.hpp>
#include <iomanip>
#include <fstream>

using json = nlohmann::json;
using std::string;
using namespace httplib;
//получаем данные погоды 
json GetWeather()
{
    Client get_time("http://api.openweathermap.org");
    auto res = get_time.Get("/data/2.5/onecall?id=524901&lat=44.95719&lon=34.11079&exclude=current,minutely,daily,alerts&units=metric&lang=ru&appid=bb693a45bf038ad8c1cc887c8a5bd872");
    if (res) {
        if (res->status == 200)
        {
            json result = res->body;
            return result;
        }
        else
        {
            std::cout << "Status code: " << res->status << std::endl;
        }
    }
    else
    {
        auto err = res.error();
        std::cout << "Error code: " << err << std::endl;
    }
}
//получаем данные времени 
string GetTime()
{
    Client get_time("http://worldtimeapi.org");
    auto res = get_time.Get("/api/timezone/Europe/Simferopol");
    if (res) {
        if (res->status == 200)
        {
            return res->body;
        }
        else
        {
            std::cout << "Status code: " << res->status << std::endl;
            return "Error";//возвращает эту строку, если сервер не отвечает
        }
    }
    else
    {
        auto err = res.error();
        std::cout << "Error code: " << err << std::endl;
    }
}
//функция проверяет, пустой ли файл (если первый символ пустой, то и файл пустой)

bool isEmptyFile(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}
//записывает кэш в файл
void cacheWriter(json cache)
{
    std::ofstream write("cache.json");
    std::cout << "Cache succesfully generated\n";
    write << std::setw(2) << cache << std::endl;
}
//проверяет, какой по счёту элемент массива погоды взять 
int whatHour(json cache)//возвращает номер элемента массива с погодой
{
    int currentHour = 2021;//если кеш устарел, то текущий час так и останется 2021
    long unixtime;

    string time = GetTime();//получаем время в json

    while (time == "Error")//теоретически должно отправлять запросы к апи времени, если выпала эта строка, не удалось проверить
    {
        time = GetTime();
    }

    json currentJson = json::parse(time);//парсим json (достаём из него данные в нужном виде)
    unixtime = currentJson["unixtime"];//присваиваем переменной текущее время из api
    for (int i = 0; i < 48; i++)//сравниваем время в массиве почасовой погоды с текущим
    {
        if (unixtime < cache["hourly"][i]["dt"])
        {
            currentHour = i;//если нашлось время, большее, чем текущее, то присваиваем номер этого элемента
            break;
        }
    }
    return currentHour;
}

string getCache()//читает кэш в переменную
{   //читаем кеш из файла
    std::ifstream read("cache.json");
    json cache;
    bool notExistCache = !read.is_open() or isEmptyFile(read);//если файл не открылся или пустой, то true

    if (notExistCache)
    {
        cache = GetWeather();//тогда получаем данные о погоде от сервиса
        cacheWriter(cache);//и отправляем их на запись в файл с кешем
    }
    else
    {
        read >> cache;//если кеш существует, то просто считываем его в переменную
        std::cout << "Cache succesfully read\n";
    }

    return cache;//функция возвращает переменную с кешем
}

string widgetGenerator(string widgetTempl, json cache, int curr_hour)//эта функция заменяет строки в шаблоне на данные погоды
{
    string deskTempl = "{hourly[i].weather[0].description}";
    string iconTempl = "{hourly[i].weather[0].icon}";
    string hourlyTempl = "{hourly[i].temp}";
    //достаём данные из кэша в переменную
    string temp = std::to_string(int(round(cache["hourly"][curr_hour]["temp"].get<double>())));
    string desk = cache["hourly"][curr_hour]["weather"][0]["description"];
    string icon = cache["hourly"][curr_hour]["weather"][0]["icon"];

    widgetTempl.replace(widgetTempl.find(deskTempl), deskTempl.length(), desk);
    widgetTempl.replace(widgetTempl.find(iconTempl), iconTempl.length(), icon);
    widgetTempl.replace(widgetTempl.find(hourlyTempl), hourlyTempl.length(), temp);
    widgetTempl.replace(widgetTempl.find(hourlyTempl), hourlyTempl.length(), temp);
    return widgetTempl;
}

void gen_response(const Request& req, Response& res)//генерирует страничку с погодой
{
    json cache = json::parse(getCache());//получает кэш из функции и парсит его
    int currentHour = whatHour(cache);//получает номер текущего элемента массива с погодой

    if (currentHour == 2021)//если он не изменился, то надо обновить кеш
    {
        json tempCache = GetWeather();//получаем данные погоды от сервиса
        cacheWriter(tempCache);//записываем их в файл
        cache = json::parse(getCache());//и снова получаем их из файла и парсим
        currentHour = whatHour(cache);//обновляет номер текущего элемента массива с погодой, чтобы не было 2021
    }
    //чтение шаблона в строковую переменную
    string widgetTemplate;
    std::ifstream readWidget("template.html");
    if (readWidget.is_open())
    {
        getline(readWidget, widgetTemplate, '\0');
    }
    else
    {
        std::cout << "Can`t open template\n";
    }

    string output = widgetGenerator(widgetTemplate, cache, currentHour);//заменяем необходимые строки на данные погоды
    res.set_content(output, "text/html");//вывод на страницу
}

void gen_response_raw(const Request& req, Response& res)
{//аналогично предыдущей функции
    json cache = json::parse(getCache());
    int currentHour = whatHour(cache);

    if (currentHour == 2021)
    {
        json tempCache = GetWeather();
        cacheWriter(tempCache);
        cache = json::parse(getCache());
        currentHour = whatHour(cache);
    }
    //достаём только нужные для клиента данные из кеша в переменную с погодой
    json data;
    int temp = round(cache["hourly"][currentHour]["temp"].get<double>());
    string desk = cache["hourly"][currentHour]["weather"][0]["description"];
    //записываем их в json
    data["temperature"] = temp;
    data["description"] = desk;
    res.set_content(data.dump(), "text/json");//выводим этот json на страницу
}

int main()
{//запускаем сервер
    Server weather;
    weather.Get("/", gen_response);//при запросе на / (localhost:3000) вызывается функция gen_response
    weather.Get("/raw", gen_response_raw);//при запросе на /raw (localhost:3000/raw) вызывается функция gen_response_raw
    std::cout << "Start server... OK\n";
    weather.listen("localhost", 3000);
}
