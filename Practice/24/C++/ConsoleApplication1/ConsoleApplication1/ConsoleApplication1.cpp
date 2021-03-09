#include <nlohmann/json.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using json = nlohmann::json;
int main()
{   json in_json;
    json out_json = json::array();
    json storage_working_data;
    std::ifstream fin("in.json"); // Открываем файл для чтения
    fin >> in_json;
    fin.close(); // Закрываем файл для чтения
    int array_size = sizeof(in_json) / sizeof(in_json[0]); // Размер массива файла "in.json"
    int number_of_users = 0;
    int task_completed = 0;
    for (int i = 0; i <= array_size; i++) {
        if (in_json[i]["userId"] > number_of_users) {
            number_of_users = in_json[i]["userId"];
        }
        for (int j = 1; j <= number_of_users; j++) {
            if (in_json[i]["completed"] == true && in_json[i]["userId"] == j) {
                task_completed +=1;
            }
            if (task_completed > 0) {
                storage_working_data["task_completed"] = task_completed;
                storage_working_data["userId"] = j;
                out_json.push_back(storage_working_data);
            }
        }
    }
    std::ofstream fout("out.json"); // Открываем файл для записи
    fout << std::setw(2) << out_json << std::endl;
    
    fout.close();// Закрываем файл для записи
 
}

