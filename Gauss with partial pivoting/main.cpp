// Metoda  lui Gauss cu pivotare partiala
	
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n;
	float A[10][10];
	float piv, aux;
	int lin;
	int permutari = 1;

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
           
		for (int i = k + 1; i <= n; i++)
		{
			if (piv < fabs(A[i][k]))
			{
				piv = fabs(A[i][k]);
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
				aux = A[k][j];
				A[k][j] = A[lin][j];
				A[lin][j] = aux;
				permutari++;
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

	if (A[n][n] == 0)
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

	for (int i = 1; i <= n; i++)
	{
		cout << endl << "X" << i << "=" << A[i][n + 1] << endl;
	}

	return 0;
}
