#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n, i, j, k, lin, permutari = 1;
	float a[10][10], y[10][10], piv, aux;

	cout << "n: "; cin >> n;
	cout << "Introduceti elementele matricei: " << endl;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cout << "a[" << i << "][" << j << "] = "; cin >> a[i][j];
		}
	}

	cout << endl << "Introduceti elementele vectorului y(0): " << endl;

	for (i = 1; i <= n; i++)
	{
		cout << "y[" << i << "][" << n << "] = "; cin >> y[i][n];
	}

	for (j = n - 1; j >= 1; j--)
	{
		for (i = 1; i <= n; i++)
		{
			y[i][j] = 0;
			
			for (k = 1; k <= n; k++)
			{
				y[i][j] = y[i][j] + a[i][k] * y[k][j + 1];
			}
		
		}

	}

	for (i = 1; i <= n; i++)
	{
		y[i][n + 1] = 0;

		for (k = 1; k <= n; k++)
		{
			y[i][n + 1] = y[i][n + 1] + a[i][k] * y[k][1];
		}

		y[i][n + 1] = -y[i][n + 1];

	}

	for (k = 1; k <= n - 1; k++)
	{
		piv = fabs(y[k][k]);
		lin = k;

		for (int i = k + 1; i <= n; i++)
		{
			if (piv < fabs(y[i][k]))
			{
				piv = fabs(y[i][k]);
				cout << "Pentru etapa " << i - 1 << " pivotul este " << piv << "." << endl;      //etapa curenta
				cout << "Pivotul se afla pe linia " << i << " si coloana " << k << " " << endl;    //coordonatele pivotului
				lin = i;
			}

		}

		if (piv == 0)
		{
			cout << "Sistemul nu are solutie unica!" << endl;
			exit(0);
		}

		if (lin != k)
		{
			for (int j = k; j <= n + 1; j++)
			{
				cout << "S-au realizat " << permutari << " permutari." << endl;    //nr.de permutari(se va incrememta pentru fiecare element; de aici nr.suplimentar de permutari)
				cout << "Se vor permuta liniile " << k << " si " << lin << endl;   //liniile ce urmeaza a fi permutate
				aux = y[k][j];
				y[k][j] = y[lin][j];
				y[lin][j] = aux;
				permutari++;
			}

		}

		for (i = k + 1; i <= n; i++)
		{
			y[i][k] = y[i][k] / y[k][k];

			for (j = k + 1; j <= n + 1; j++)
			{
				y[i][j] = y[i][j] - y[i][k] * y[k][j];
			}
		}



	}

	if (y[n][n] == 0)
	{
		cout << "Sistemul nu are solutie unica!";
		exit(0);
	}

	y[n][n + 1] = y[n][n + 1] / y[n][n];

	for (i = n - 1; i >= 1; i--)
	{
		float S = 0;
		for (j = i + 1; j <= n; j++)
		{
			S = S + y[i][j] * y[j][n + 1];
		}
		y[i][n + 1] = (y[i][n + 1] - S) / y[i][i];
	}

	cout << endl;
	cout << "Coeficientii polinomului caracteristic sunt: " << endl;

	for (i = 1; i <= n; i++)
	{
		cout << endl << "C" << i << " = " << y[i][n + 1] << endl;
	}

	return 0;
}

