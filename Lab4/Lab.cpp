//// Lab 4

#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>

using namespace std;

void main()
{
	int x, y, w, chromatic;
	int summond[6];
	int m[15] =   { 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 5 };
	int n[15] =   { 2, 3, 4, 5, 6, 3, 4, 5, 6, 4, 5, 6, 5, 6, 6 };
	int contiguity[6][6];
	int incidence[6][11];
	int Rmn[15] = { 2, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1 };

	//cout << "Input values:\n";
	//for (int i = 0; i <= 14; i++)
	//{
	//	cin >> Rmn[i];
	//}


	int k = 0, j = 0, z = -1;
	for (int i = 0; i <= 5; i++)
	{
		z += 1;
		for (j = z; j <= 5; j++)
		{
			if (i == j)
			{
				contiguity[i][j] = 0;
			}
			else
			{
				contiguity[i][j] = Rmn[k];
				contiguity[j][i] = Rmn[k++];
			}
		}
	}
	cout << "\nMatrix of contiguity:\n\n";
	for (int i = 0; i <= 5; i++)
		for (int k = 0, j = 0; j <= 5; j++)
		{
			cout << contiguity[i][j] << " ";
			if (j == 5) cout << "\n";
		}


	int k1 = 6, k2 = 0;
	for (int i = 0; i < 15; i++) {
		k2 += Rmn[i];
	}
	for (int i = 0; i < k1; i++)
		for (int j = 0; j < k2; j++)
			incidence[i][j] = 0;
	x = 0;
	for (int j = 0; j < 15; j++) {
		while (Rmn[j] == 0)
			j++;
		for (int i = 0; i < Rmn[j]; i++) {
			//cout << m[j] << n[j] << Rmn[j] << endl;
			//cout << j << x << endl;
			incidence[m[j] - 1][x] = 1;
			incidence[n[j] - 1][x] = 1;
			x++;
		}
	}
	cout << "\nMatrix of incedent...:\n\n";
	for (int i = 0; i < k1; i++) {
		for (int j = 0; j < k2; j++)
		{
			cout << incidence[i][j] << " ";
			//if (j == 5)	cout << "\n";
		}
		cout << "\n";
	}

	_getch();
}
