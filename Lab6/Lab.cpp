// Lab 6
#include <iostream>
#include <iomanip>
#include <string>
#include <io.h>
#include <fcntl.h>

using namespace std;

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);

    wcout << L"Lab 6" << endl << endl;
    int R1[5][2] = { {1, 2}, {1, 3}, {1, 4}, {2, 3}, {4, 3} };
    int A[4] = { 1, 2, 3, 4 };

    wcout << " R1 = { ";
    for (int i = 0; i < 5; i++) {
        wcout << "(" << setw(2) << R1[i][0] << "," << setw(2) << R1[i][1] << ")";
        if (i == 4)
            wcout << " ";
        else
            wcout << ", ";
    }
    wcout << "}" << endl << endl;

    wcout << " A = {";
    for (int i = 0; i < 4; i++) {
        wcout << setw(2) << A[i];
        if (i == 3)
            wcout << " ";
        else
            wcout << ", ";
    }
    wcout << "}" << endl << endl;

    wcout << " A^2 = { ";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            wcout << "(" << setw(2) << A[i] << "," << setw(2) << A[j] << ")";
            if (i == 3 && j == 3)
                wcout << " ";
            else
            wcout << ", ";
        }
    }
    wcout << "}" << endl << endl;

    wcout << L"Задати відношення за допомогою матриці та графа." << endl << endl;

    int x = 0, y = 0;
    wcout << setw(4) << " \ " << setw(4) << "1" << setw(4) << "2" << setw(4) << "3" << setw(4) << "4" << endl;
    for (int i = 0; i < 4; i++) {
        wcout << setw(4) << i + 1;
        for (int j = 0; j < 4; j++) {
            if (R1[x][0] == i + 1 && R1[x][1] == j + 1) {
                wcout << setw(4) << 1;
                x++;
            }
            else {
                wcout << setw(4) << 0;
            }
        }
        wcout << endl;
    }
    wcout << endl;

    wcout << "1    2" << endl;
    wcout << "*----*" << endl;
    wcout << "|\\  /" << endl;
    wcout << "| \\/ " << endl;
    wcout << "| /\\ " << endl;
    wcout << "|/  \\" << endl;
    wcout << "*----*" << endl;
    wcout << "3    4" << endl;
    wcout << endl;

    int v1 = 0, v3 = 0, v4 = 0, v5 = 0, v6 = 0;
    int j;
    for (int i = 0; i < 5; i++) {
        j = 0;
        if (R1[i][0] == R1[i][1]) {
            v1++;
        }
        while (j < 5) {
            if (R1[i][0] == R1[j][1] && R1[i][1] == R1[j][0])
                v3++;
            j++;
        }
    }

    wcout << L"Відношення R1 на множині A^2 є : " << endl;
    if (v1 == 4)
        wcout << L" - рефлексивне" << endl;
    else 
        wcout << L" - не рефлексивне" << endl;
    if (v1 == 0)
        wcout << L" - іррефлексивне" << endl;
    else
        wcout << L" - не іррефлексивне" << endl;
    if ((v3 - v1) == 5)
        wcout << L" - симетричне" << endl;
    else
        wcout << L" - не симетричне" << endl;
    if ((v3 - v1) == 0)
        wcout << L" - антисиметричне" << endl;
    else
        wcout << L" - не антисиметричне" << endl;
    if (v3 == 0)
        wcout << L" - асиметричне" << endl;
    else
        wcout << L" - не асиметричне" << endl;
    wcout << L" - транзитивне" << endl;

    return 0;
}
