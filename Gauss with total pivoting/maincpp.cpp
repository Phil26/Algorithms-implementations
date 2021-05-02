// Metoda Gauss pentru pivotare totala

#include <iostream>
#include <math.h>
#define EPSILON 0.00001
using namespace std;

int main()
{
	int n;
	float A[10][10];
	float piv, aux;
	int lin, col, npc = 0, c1[10], c2[10];
	

	cout << "Introduceti dimensiunea matricei: ";
	cin >> n;

	cout << "Introduceti elementele matricei" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n + 1; j++)
		{
			cout << "A[" << i << "][" << j << "] = ";
			cin >> A[i][j];
		}
	}

	cout << endl;

	for (int k = 1; k <= n - 1; k++)
	{
		piv = fabs(A[k][k]);
		lin = k;
		col = k;

		for (int j = k; j <= n; j++)
		{
			for (int i = k; i <= n; i++)
			{

				if (piv < fabs(A[i][j]))
				{
					piv = fabs(A[i][j]);
					lin = i;
					col = j;
				}

			}

			if (piv <= EPSILON)
			{
				cout << "Sistemul nu are solutie unica!" << endl;
				exit(0);
			}


			if (lin != k)
			{
				for (int j = k; j <= n + 1; j++)
				{
					aux = A[k][j];
					A[k][j] = A[lin][j];
					A[lin][j] = aux;
				}

			}

			if (col != k)
			{
				npc++;
				c1[npc] = k;
				c2[npc] = col;
				for (int i = 1; i <= n; i++)
				{
					aux = A[i][k];
					A[i][k] = A[i][col];
					A[i][col] = aux;

				}
			}

			for (int i = k + 1; i <= n; i++)
			{
				A[i][k] = A[i][k] / A[k][k];

				for (int j = k + 1; j <= n + 1; j++)
				{
					A[i][j] = A[i][j] - A[i][k] * A[k][j];
				}
			}
		}
	}

	if (fabs(A[n][n]) <= EPSILON)
	{
		cout << "Sistemul nu are solutie unica!";
		exit(0);
	}

	A[n][n + 1] = A[n][n + 1] / A[n][n];

	for (int i = n - 1; i >= 1; i--)
	{
		float S = 0;
		for (int j = i + 1; j <= n; j++)
		{
			S = S + A[i][j] * A[j][n + 1];
		}
		A[i][n + 1] = (A[i][n + 1] - S) / A[i][i];
	}

	if (npc != 0)
	{
		for (int i = npc; i >= 1; i--)
		{
			
			aux = A[c1[i]][n + 1];
			A[c1[i]][n + 1] = A[c2[i]][n + 1];
			A[c2[i]][n + 1] = aux;


		}

	}

	for (int i = 1; i <= n; i++)
	{
		cout << endl << "X" << i << " = " << A[i][n + 1] << endl;
	}

	return 0;
}
