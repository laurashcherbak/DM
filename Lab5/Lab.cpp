// Lab 5
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Process2()
{
    string s = "34+75-*63/^";
    string op;
    int a = NULL, b = NULL, c = NULL, d = NULL, e = NULL, f = NULL, t;

    cout << "Expression: ";
    for (int i = 0; i < s.length(); i++) {
        cout << s[i] << " ";
    }
    cout << endl;

    int i = 0;
    while (i < s.length()) {
        op = s[i];
        if (s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/' && s[i] != '^')
        {
            t = atoi(op.c_str());
            if (a == NULL) {
                a = t;
            }
            else if (b == NULL) {
                b = t;
            }
            else if (c == NULL) {
                c = t;
            }
            else if (d == NULL) {
                d = t;
            }
            else if (e == NULL) {
                e = t;
            }
            else if (f == NULL) {
                f = t;
            }
        }

        if (op == "+") {
            if (a != NULL && b != NULL && c != NULL && d != NULL && e == NULL) {
                d = c + d;
                d = NULL;
            }
            else if (a != NULL && b != NULL && c != NULL && d == NULL) {
                b = b + c;
                c = NULL;
            }
            else if (a != NULL && b != NULL && c == NULL) {
                a = a + b;
                b = NULL;
            }
        }
        else if (op == "-") {
            if (a != NULL && b != NULL && c != NULL && d != NULL && e == NULL) {
                d = c - d;
                d = NULL;
            }
            else if (a != NULL && b != NULL && c != NULL && d == NULL) {
                b = b - c;
                c = NULL;
            }
            else if (a != NULL && b != NULL && c == NULL) {
                a = a - b;
                b = NULL;
            }
        }
        else if (op == "*") {
            if (a != NULL && b != NULL && c != NULL && d != NULL && e == NULL) {
                d = c * d;
                d = NULL;
            }
            else if (a != NULL && b != NULL && c != NULL && d == NULL) {
                b = b * c;
                c = NULL;
            }
            else if (a != NULL && b != NULL && c == NULL) {
                a = a * b;
                b = NULL;
            }
        }
        else if (op == "/") {
            if (a != NULL && b != NULL && c != NULL && d != NULL && e == NULL) {
                d = c / d;
                d = NULL;
            }
            else if (a != NULL && b != NULL && c != NULL && d == NULL) {
                b = b / c;
                c = NULL;
            }
            else if (a != NULL && b != NULL && c == NULL) {
                a = a / b;
                b = NULL;
            }
        }
        else if (op == "^") {
            if (a != NULL && b != NULL && c != NULL && d != NULL && e == NULL) {
                d = pow(c, d);
                d = NULL;
            }
            else if (a != NULL && b != NULL && c != NULL && d == NULL) {
                b = pow(b, c);
                c = NULL;
            }
            else if (a != NULL && b != NULL && c == NULL) {
                a = pow(a, b);
                b = NULL;
            }
        }

        //cout << "i= " << i << " a= " << a << " b= " << b << " c= " << c << " d= " << d << " e= " << e << " f= " << f << endl;

        i++;
    }
    cout << "Result = " << a << endl;
}

void Process1()
{

    string str, stack;
    char word, word_last;
    int i = 0;
    string s = "(n-m)+(5*m)-(n+m)/9";

    cout << "Expression: ";
    for (int i = 0; i < s.length(); i++) {
        cout << s[i] << " ";
    }
    cout << endl;

    while (i < s.length()) {
        word = s[i];

        if (((word >= 0x30) && (word <= 0x39)) || ((word >= 0x61) && (word <= 0x7A))) { //если символ это число или буква
            if ((word_last >= 48) && (word_last <= 57)) { // Проверка, является ли предыдущий символ - числом
                str += word; //Если да , то просто добавляем его, тем самым не разрушая число
            }
            else {
                str += ' '; // В противном  случае добавляем пробел и добавляем символ в главную строку
                str += word;
            }
        }

        if ((word == 0x2A) || (word == 0x2B) || (word == 0x2D) || (word == 0x2F) || (word == 0x5E)) { //если символ это операнд
            if (stack.empty()) { //  Если стэк пустой - то просто кладем символ в стэк
                stack += word;
            }
            else {	 // Если стэк не пуст
                if ((stack.back() >= word) || (stack.back() == word - 1) || (stack.back() == word + 1)) { // Если  верхний элемент стэка имеет больший приоритет 
                    while ((stack.back() >= word) || (stack.back() == word - 1) || (stack.back() == word + 1)) { //выталкиваем все элементы из стэка
                        str += ' ';														//До тех пор, пока приоритет верхнего элемента не будет
                        str += stack.back();													//ниже входящего символа
                        stack.pop_back();
                    }
                    stack += word;
                }
                else { // если же верхний элемент ниже приоритетом - то просто кладем символ в стэк
                    stack += word;
                }
            }
        }
        if (word == '(') { //Если символ - открывающая скобка
            stack += word;  //добавляем ее в стэк
        }
        if (word == ')') {    //Если встречающийся символ - закрывающая скобка
            while (stack.back() != '(') { // пока в стеке не встретится открывающая скобка 
                str += ' ';        // выталкиваем в главную строку  все символы
                str += stack.back();
                stack.pop_back();
            }
            stack.pop_back(); //Удаляем открывающую скобку из стека
        }

        word_last = word; //Присваиваем значение текущего символа для проверки в последующем цикле

            //cout << "Numb:" << i++ << endl; // Распечатка пошаговых действий
            //cout << "Word:  |" << word << endl;
            //cout <<"STR:| "  << str <<"|  SRA:|" << stack << endl;

        i++;
    }
    while (!stack.empty()) { //При окончании строки выталкиваем все символы из стека
        str += ' ';
        str += stack.back();
        stack.pop_back();
    }

    cout << "Result: " << str << endl;
}



int main()
{

    cout << "Task 5.1" << endl;
    Process1();
    cout << endl;
    cout << "Task 5.2" << endl;
    Process2();

    return 0;
}
