// Lab 2
#include <iostream>
#include <string>

using namespace std;

void PrintArray(int* a, const int size) {
    cout << " = {";
    for (int i = 0; i < size; i++) {
        cout << (i > 0 ? ", " : "") << a[i];
    }
    cout << "}" << endl;
}

void Not(int* a, int* not_a, int* u, int k_a, int k_u) {
    bool equal;

    int t = 0;
    for (int i = 0; i < k_u; i++)
    {
        equal = false;
        for (int j = 0; j < k_a; j++)
        {
            if (u[i] == a[j])
            {
                equal = true;
                break;
            }
        }
        if (!equal) {
            not_a[t] = u[i];
            t++;
        }
    }
}

int Min(int a, int b) {
    if (a < b)
        return a;
    else 
        return b;
}

int Max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int Union(int* A, int* B, int* C, int cA, int cB, int cC) {
    int in_a = 0;
    int in_b = 0;
    int in_c = 0;
    while (in_a < cA && in_b < cB) {
        int el = Min(A[in_a], B[in_b]);
        C[in_c++] = el;
        while (in_a < cA && A[in_a] == el) {
            ++in_a;
        }
        while (in_b < cB && B[in_b] == el) {
            ++in_b;
        }
    }
    while (in_a < cA) {
        C[in_c++] = A[in_a++];
    }
    while (in_b < cB) {
        C[in_c++] = B[in_b++];//check -> in_a or in_b
    }

    return in_c;
}

int Intersect(int* A, int* B, int* C, int cA, int cB, int cC) {
    int in_a = 0;
    int in_b = 0;
    int in_c = 0;
    while (in_a < cA && in_b < cB) {
        while (in_b < cB && A[in_a] > B[in_b]) {
            ++in_b;
        }

        if (in_b < cB && A[in_a] == B[in_b]) {
            C[in_c] = A[in_a];
            in_c++;
            in_b++;
        }
        in_a++;
    }

    return in_c;
}


int main()
{
    const int kU = 25;
    const int kA = 11;
    const int kB = 11;
    const int kC = 9;

    int U[kU] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    int A[kA] = { 1, 6, 7, 8, 9, 13, 14, 15, 19, 20, 24};
    int B[kB] = { 1, 2, 3, 5, 6, 7, 13, 18, 19, 20, 23};
    int C[kC] = { 1, 2, 12, 13, 14, 15, 19, 20, 25};

    cout << "U";
    PrintArray(U, kU);
    cout << endl;

    cout << "A";
    PrintArray(A, kA);
    cout << endl;

    cout << "B";
    PrintArray(B, kB);
    cout << endl;

    cout << "C";
    PrintArray(C, kC);
    cout << endl;

    //not A
    const int k_notA = kU - kA;
    int* notA = new int[k_notA];
    Not(A, notA, U, kA, kU);
    cout << "-" << endl << "A";
    PrintArray(notA, k_notA);
    cout << endl;

    //z1
    int k_z1 = k_notA + kB;
    int* z1 = new int[k_z1];
    k_z1 = Union(notA, B, z1, k_notA, kB, k_z1);
    cout << "     -" << endl << "z1 = A v B";
    PrintArray(z1, k_z1);
    cout << endl;

    //z2
    int k_z2 = Max(k_z1, kA);
    int* z2 = new int[k_z2];
    k_z2 = Union(B, A, z2, kB, kA, k_z2);
    cout << "z2 = A v B";
    PrintArray(z2, k_z2);
    cout << endl;

    // z3
    int k_z3 = Max(k_z2, k_z1);
    int* z3 = new int[k_z3];
    k_z3 = Intersect(z1, z2, z3, k_z1, k_z2, k_z3);
    cout << "          -" << endl << "z3 = z1 ^ z2";
    PrintArray(z3, k_z3);
    cout << endl;

    //not z3
    const int k_notZ3 = kU - k_z3;
    int* notZ3 = new int[k_notZ3];
    Not(z3, notZ3, U, k_z3, kU);
    cout << "-" << endl << "z3";
    PrintArray(notZ3, k_notZ3);
    cout << endl;

    //not C
    const int k_notC = kU - kC;
    int* notC = new int[k_notC];
    Not(C, notC, U, kC, kU);
    cout << "-" << endl << "C";
    PrintArray(notC, k_notC);
    cout << endl;


    // not z4
    int k_notZ4 = Max(k_notZ3, kC);
    int* notZ4 = new int[k_notZ4];
    k_notZ4 = Intersect(notZ3, C, notZ4, k_notZ3, kC, k_notZ4);
    cout << "     -" << endl << "z4 = z3 ^ C";
    PrintArray(notZ4, k_notZ4);
    cout << endl;

    //z4
    const int k_z4 = kU - k_notZ4;
    int* z4 = new int[k_z4];
    Not(notZ4, z4, U, k_notZ4, kU);
    cout << "-" << endl << "z4";
    PrintArray(z4, k_z4);
    cout << endl;

    delete[] z4;
    delete[] notZ4;
    delete[] notC;
    delete[] notZ3;
    delete[] z3;
    delete[] z2;
    delete[] z1;
    delete[] notA;


    return 0;
}
