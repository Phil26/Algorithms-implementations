#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n, itmax, i, j, it;
	float a[10][10], epsilon, x[10], b[10], max, S, y[10];
	cout << "n: "; cin >> n;
	
	cout << "Matrice sistemului: " << endl;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				cout << "a[" << i << "][" << j << "] = "; cin >> a[i][j];
			}
		}
		cout << "Componentele termenului liber: " << endl;
	for (i = 1; i <= n; i++)
	{
		cout << "b[" << i << "] = "; cin >> b[i];
	}

	cout << "Componentele initiale ale solutiei arbitrare: " << endl;
	for (i = 1; i <= n; i++)
	{
		x[i] = 0;
		cout << "x["<< i <<"] = " << x[i] << endl;
	}

	cout << "Numarul maxim de iteratii admise: ";
	cin >> itmax;
	cout << "epsilon: "; cin >> epsilon;
	cout << "Precizia prestabilita -> epsilon = " << epsilon << endl;

	it = 0;

	do
	{
		max = 0;
		for (i = 1; i <= n; i++)
		{
			S = 0;
			for (j = 1; j <= n; j++)
			{
				if (j != i)
				{
					S = S + a[i][j] * x[j];
				}

			}
			y[i] = (b[i] - S) / a[i][i];
			if (max < fabs(y[i] - x[i]))
			{
				max = fabs(y[i] - x[i]);
			}

		}

		for (i = 1; i <= n; i++)
		{
			x[i] = y[i];
		}


		cout << "Solutia sistemului la iteratia numarul " << it << " este: " << endl;
		for (i = 1; i <= n; i++)
		{
			cout << "x[" << i << "] = " << x[i] << endl;
		}

		it++;
	} while (max > epsilon && it <= itmax);

	if(it > itmax)
	{
		cout << "Nu se poate obtine solutie in " << itmax << " iteratii cu precizia " << epsilon << endl;
		return -1;

	}

	cout << "Solutia obtinuta in " << it << " iteratii este: " << endl;
	for (i = 1; i <= n; i++)
	{
		cout << "x[" << i << "] = " << x[i] << endl;
	}


	return 0;
}