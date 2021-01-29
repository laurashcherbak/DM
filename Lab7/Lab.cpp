#ifndef _CRT_SECURE_NO_WARNINGS
    #define _CRT_SECURE_NO_WARNINGS
#endif // !#define _CRT_SECURE_NO_WARNINGS

// Lab 6
#include <iostream>
#include <iomanip>
#include <string>
//#include <io.h>
//#include <fcntl.h>

//#include <iostream>
#include <stdio.h>
#include <conio.h>
//#include <string>

using namespace std;

typedef string Info;
struct Elem
{
    Elem* link1;
    Elem* link2;
    Elem* link3;
    Elem* link4;
    Elem* link5;
    Info info;
};

void PrintTree(Elem* root, int level)
{
    if (root != NULL)
    {
        PrintTree(root->link1, level + 1);
        PrintTree(root->link2, level + 1);
        for (int i = 1; i <= level; i++)
            cout << " ";
        cout << root->info << endl;
        PrintTree(root->link3, level + 1);
        PrintTree(root->link4, level + 1);
        PrintTree(root->link5, level + 1);
    }
}

void Task1()
{
    Elem* p;
    p = new Elem;
    p->info = 'E';
    p->link1 = new Elem;
    p->link1->info = '(';
    p->link2 = new Elem;
    p->link2->info = 'E';
    p->link2->link1 = new Elem;
    p->link2->link1->info = 'C';
    p->link2->link1->link1 = new Elem;
    p->link2->link1->link1->info = '2';
    p->link3 = new Elem;
    p->link3->info = '*';
    p->link4 = new Elem;
    p->link4->info = 'E';
    p->link4->link1 = new Elem;
    p->link4->link1->info = '(';
    p->link4->link2 = new Elem;
    p->link4->link2->info = 'E';
    p->link4->link2->link1 = new Elem;
    p->link4->link2->link1->info = 'V';
    p->link4->link2->link1->link1 = new Elem;
    p->link4->link2->link1->link1->info = 'X';
    p->link4->link3 = new Elem;
    p->link4->link3->info = '+';
    p->link4->link4 = new Elem;
    p->link4->link4->info = 'E';
    p->link4->link4->link1 = new Elem;
    p->link4->link4->link1->info = 'E';
    p->link4->link4->link1->link1 = new Elem;
    p->link4->link4->link1->link1->info = 'V';
    p->link4->link4->link1->link1->link1 = new Elem;
    p->link4->link4->link1->link1->link1->info = 'Y';
    p->link4->link4->link2 = new Elem;
    p->link4->link4->link2->info = '+';
    p->link4->link4->link3 = new Elem;
    p->link4->link4->link3->info = 'E';
    p->link4->link4->link3->link1 = new Elem;
    p->link4->link4->link3->link1->info = 'C';
    p->link4->link4->link3->link1->link1 = new Elem;
    p->link4->link4->link3->link1->link1->info = '1';
    p->link4->link5 = new Elem;
    p->link4->link5->info = ')';
    p->link5 = new Elem;
    p->link5->info = ')';

    //for (int i = 1; i < 8; i++) cout << " "; cout << p->link1->link1->link1->info << endl;
    //for (int i = 1; i < 6; i++) cout << " "; cout << p->link1->link1->info << endl;
    //for (int i = 1; i < 4; i++) cout << " "; cout << p->link1->info << endl;
    //for (int i = 1; i < 2; i++) cout << " "; cout << "//" << endl;
    ////for (int i = 1; i < 2; i++) cout << " "; cout << p->link2->info << endl;
    //cout << p->info; cout << "-" << p->link2->info << endl;
    //for (int i = 1; i < 2; i++) cout << " "; cout << "\\\\" << endl;
    //for (int i = 1; i < 3; i++) cout << " "; cout << "\\" << p->link3->info << endl;

    //PrintTree(p, 0);

}

void Task2()
{
    string A = "101";
    string B = "010";
    string S1 = "1";
    string S2 = "0";

    cout << "L(G) = { " << S1 << A << ", " << S2 << B << " }";
}

int main() 
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);

    Task1();
    Task2();

    Count();

    return 0;
}
