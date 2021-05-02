#include <iostream>
using namespace std;

int main()
{
	int n, i, j, k, h;
	int perm = 0;
	float a[10][10], aux, l[10][10], r[10][10];
	float S, piv;
	cout << "n: "; cin >> n;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n + 1; j++)
		{
			cout << "a["<< i <<"]["<< j <<"] = ";
			cin >> a[i][j];
		}
	}

	if (a[1][1] == 0)
	{
		i = 1;
		do
		{
			i = i + 1;

		} while (a[i][1] == 0 && i <= n);
	     
		if (i > n)
		{
			cout << "Sistemul nu are solutie unica";
			return 0;
		}
	
		for (j = 1; j <= n + 1; j++)
		{
			aux = a[1][j];
			a[1][j] = a[i][j];
			a[i][j] = aux;
			
		}
	}

	for (i = 2; i <= n; i++)
	{
		a[i][1] = a[i][1] / a[1][1];
	}

	for (k = 2; k <= n; k++)
	{
		i = k;
		do
		{
			S = 0;
			piv = 0;
			for (h = 1; h <= k - 1; h++)
			{
				S = S + a[i][h] * a[h][k];
			}

			piv = a[i][k] - S;
			i = i + 1;
		} while (piv == 0 && i <= n);

		if (piv == 0)
		{
			cout << "Sistemul nu are solutie unica";
			return 0;
		}

		if (i != k + 1)
		{
			for (j = 1; j <= n + 1; j++)
			{
				aux = a[k][j];
				a[k][j] = a[i - 1][j];
				a[i - 1][j] = aux;



			}
			cout << endl << "S-au interschimbat liniile " << k << " si " << i - 1 << endl;
			perm++;

		}
	

		for (j = k; j <= n; j++)
		{
			S = 0;

			for (h = 1; h <= k - 1; h++)
			{
				S = S + a[k][h] * a[h][j];
			}
			
			a[k][j] = a[k][j] - S;
		}

		

		for (i = k + 1; i <= n; i++)
		{
			S = 0;
			for (h = 1; h <= k - 1; h++)
			{
				S = S + a[i][h] * a[h][k];
			}
			a[i][k] = (a[i][k] - S) / a[k][k];

			}
		
	}
	for (i = 2; i <= n; i++)
	{
		S = 0;
		for (k = 1; k <= i - 1; k++)
		{
			S = S + a[i][k] * a[k][n + 1];
		}
		a[i][n + 1] = a[i][n + 1] - S;
	}

	for (i = 1; i <= n; i++)
	{
		cout << endl << "y[" << i << "] = " << a[i][n + 1] << endl;
	}

	a[n][n + 1] = a[n][n + 1] / a[n][n];

	for (i = n - 1; i >= 1; i--)
	{
		S = 0;
		for (j = i + 1; j <= n; j++)
		{
			S = S + a[i][j] * a[j][n + 1];
		}
		a[i][n + 1] = (a[i][n + 1] - S) / a[i][i];
	}

	cout << "Solutia sistemului este: " << endl;

	for (i = 1; i <= n; i++)
	{
		if (a[i][n + 1] == 0)
		{
			a[i][n + 1] = -a[i][n + 1];
		}
		cout << endl << "x[" << i << "] = " << a[i][n + 1] << endl;
	}
	cout << endl << "S-au efectuat " << perm << " permutari." << endl;

	return 0;
}