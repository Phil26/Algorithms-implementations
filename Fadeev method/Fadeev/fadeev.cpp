#include <iostream>

using namespace std;

int main()
{
	int n, i, j, k, h;
	float a[10][10], b[10][10], d[10][10], c[10];

	cout << "n: "; cin >> n;
	cout << "Introdu elementele matricei: " << endl;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cout << "a[" << i << "][" << j << "] = "; cin >> a[i][j];
		}
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
			{
				b[i][j] = 1;
			}
			
			else
			{
				b[i][j] = 0;
			}
		}
	}

	for (k = 1; k <= n - 1; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				d[i][j] = 0;
			
				for (h = 1; h <= n; h++)
				{
					d[i][j] += a[i][h] * b[h][j];
				}
			
			}
		
		}

		c[k] = 0;
		
		for (i = 1; i <= n; i++)
		{
			c[k] += d[i][i];
		}

		c[k] = -c[k] / k;

		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (i == j)
				{
					b[i][j] = d[i][j] + c[k];
				}
			
				else
				{
					b[i][j] = d[i][j];
				}
			
			}
		
		}

	}


	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			d[i][j] = 0;

			for (h = 1; h <= n; h++)
			{
				d[i][j] += a[i][h] * b[h][j];
			}

		}
	}

	c[n] = 0;

	for (i = 1; i <= n; i++)
	{
		c[n] = c[n] + d[i][i];
	}

	c[n] = -c[n] / n;

	if (c[n] == 0)
	{
		cout << endl << "Matricea nu este inversabila." << endl;
	}

	else
	{
		cout << "Matricea inversata este: " << endl;
	    
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				cout << -b[i][j] / c[n];
			}
		}

	}

	cout << endl << "Coeficientii polinomului caracteristic sunt: " << endl;
	for (i = 1; i <= n; i++)
	{
		cout << c[i] << endl;
	}

	return 0;


}