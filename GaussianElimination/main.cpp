#include <iostream>
using namespace std;

int main()
{
	int n;
	float A[10][10];

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

	for (int k = 1; k <= n - 1; k++)
	{
		if (A[k][k] != 0)
		{
			for (int i = k + 1; i <= n; i++)
			{
				A[i][k] = A[i][k] / A[k][k];
				for (int j = k + 1; j <= n + 1; j++)
				{
					A[i][j] = A[i][j] - A[i][k] * A[k][j];
				}
			}
		}
		else
		{
			int lin = k;
			do
			{
				lin = lin + 1;
			} while (A[lin][k] == 0 || lin <= n);

			if (lin > n)
			{
				cout << "Sistemul nu are solutie unica!";
				exit(0);
			}

			for (int j = k; j <= n + 1; j++)
			{
				float aux = A[k][j];
				A[k][j] = A[lin][j];
				A[lin][j] = aux;
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
