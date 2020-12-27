// Lab 3
#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>

using namespace std;

int f(int x) {
    int r = 1;

    for (int i = 1; i <= x; i++) r *= i;

    return r;
}

double a(double n, const double k, const double m) {
    double an;

    if (n == 0)
        an = k;
    else if (n == 1)
        an = m;
    else
        an = -(2. / 3) * a(n - 1, k, m) + (1. / 3) * a(n - 2, k, m);

    return an;
}

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);

    int r;

    int NumberOfCards = 8;
    wcout << L"Завдання 1." << endl
        << L"    Є колода з 52 карт. Скількома способами можна розкласти 8 обраних карт?" << endl
        << L"    Рішення: 8! = " << f(NumberOfCards) << endl;

    int NumberOfCastles = 8;
    wcout << L"Завдання 2." << endl
        << L"    Визначити кількість комбінацій для заданих операцій :" << endl
        << L"    Скількома способами можна поставити 8 тур на шахову дошку так, щоб вони не били одна одну ?" << endl
        << L"    Рішення: 8! = " << f(NumberOfCastles) << endl;

    //r = (f(14) / (f(5) * f(9))) * pow(2, 5) * pow(3, 9);
    r = 11 * 13 * 14 * pow(2, 5) * pow(3, 9);
    wcout << L"Завдання 3." << endl
        << L"    Визначити у розкладанні бінома Ньютона коефіцієнт С, який відповідає заданному елементу." << endl
        << L"    Рішення: C = " << r << endl;

    wcout << L"Завдання 4." << endl
        << L"    Знайти розв‘язок рекурентного рівняння із заданими початковими умовами." << endl
        << L"    Рішення: an = 3/4 * pow(1/3, n) - (19/4) * pow(-1, n)" << endl
        << L"    Розв‘язати однорiдне лiнiйне рекурентне рiвняння за початкових умов." << endl
        << L"    Знайти a2." << endl
        << L"    Рішення: a2 = " << a(2, -4, 5) << endl
        << L"    Виразити аналiтично an." << endl
        << L"    Рішення: an = -(2/3) * a(n-1) + (1/3) * a(n-2) " << endl
        ;

    return 0;
}
