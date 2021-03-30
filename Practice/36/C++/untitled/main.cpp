#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
const auto PI = 3.141592653589793;

using namespace std;

class Point
{

private:
    double x;
    double y;
    double r;
    double φ;

    enum coord_system
    {
    Cartesian,
    Polar
    };

public:
    Point(double a1 = 0, double a2 = 0, coord_system a3 = Cartesian)
    {
        if (a3 == Cartesian)
        {
            x = a1;
            y = a2;
            r = sqrt(a1 * a1 + a2 * a2);
            φ = 1 / tan(a2 / a1);
        }
        else
        {
            r = a1;
            φ = a2;
            x = r * cos(φ);
            y = r * sin(φ);
        }
    }
    double deviation (double value)
    {
        if (value > 0)
            return (int)(value * pow(10, 10)) / pow(10, 10);
        else
            return (int)(-value * pow(10, 10)) / pow(10, 10);

    }
    bool operator ==(const Point other)
    {
        return deviation(this->x) == deviation(other.x) && deviation(this->y) == deviation(other.y);
    }

    bool operator !=(const Point other)
    {
        return !(operator == (other));
    }

    double Get_x()
    {
        return x;
    }

    double Get_y()
    {
        return y;
    }

    void Set_x(double valueX)
    {
        x = valueX;
    }

    void Set_y(double valueY)
    {
        x = valueY;
    }

    double Get_r()
    {
        return r;
    }

    double Get_φ()
    {
        return φ;
    }

    void Set_r(double valueR)
    {
        r = valueR;
    }

    void Set_φ(double valueΦ)
    {
        φ = valueΦ;
    }

    friend ostream& operator << (ostream& out, const Point& dot);
    friend istream& operator >> (istream& in, Point& dot);
};

istream& operator >> (istream& in, Point& dot)
{
    char comma;
    in >> dot.x >> comma >> dot.y;
    return in;
}

ostream& operator << (ostream& out, const Point& dot)
{
    out << '(' << dot.x << ',' << dot.y << ')';
    return out;
}
// Ваш код тут

int main() {
    std::vector<Point> original;
    std::ifstream fin("‪data.txt");
    if (!fin.is_open()) {
        std::cout << "Can't open file" << std::endl;
        return 1;
    }
    else {
        while (!fin.eof()) {
            Point p;
            fin >> p;
            fin.ignore(2); // Точки разделены двумя символами ", "
            original.push_back(p);
        }
        fin.close();
    }

    std::vector<Point> simulacrum(original);
    for (auto& p : simulacrum) {
        std::cout << p;
        p.Set_x(p.Get_x() + 10);
        p.Set_φ(p.Get_φ() + 180 * PI / 180);
        p.Set_y(-p.Get_y());
        p.Set_x(-p.Get_x() - 10);
        std::cout << p << std::endl;
    }

    if (std::equal(original.begin(), original.end(), simulacrum.begin()))
        std::cout << "\nIt works!\n";
    else
        std::cout << "\nIt not works!\n";
}
