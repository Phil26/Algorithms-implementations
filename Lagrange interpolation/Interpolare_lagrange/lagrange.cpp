#include <iostream>
using namespace std;


int main()
{


	int n, i, k, m, j, t, r;
	float x[10], f[10], z[10], L[10], P[10];

	cout << "Introduceti n: "; cin >> n;

	cout << "Introduceti valorile vectorului x: " << endl;
	
	for (i = 0; i <= n; i++)
	{
		cout << "x[" << i << "] = "; cin >> x[i];
	}

	cout << endl << "Introduceti valorile vectorului f: " << endl;

	for (i = 0; i <= n; i++)
	{
		cout << "f[" << i << "] = "; cin >> f[i];
	}

	cout << endl << "Introduceti dimensiunea vectorului z: "; cin >> m;

	cout << endl << "Introduceti elementele vectorului z: " << endl;

	for (i = 0; i <= m; i++)
	{
		cout << "z[" << i << "] = "; cin >> z[i];
	}
	for (i = 0; i <= m; i++)
	{
		for (j = 0; j <= n; j++)
		{
		
			if (z[i] < x[0] || z[i] > x[n])
			{
				cout << "Nu putem aproxima f in " << z[i] << endl;
				continue;
			}
			else if (z[i] == x[j])
			{
				cout << "Valoarea lui f in z[" << i << "] = " << z[i] << " este f[" << i << "] = " << f[i] << "." << endl;
				continue;
			}

			else
			{
				for (t = 0; t <= n; t++)
				{
					L[t] = 0;
				}

				for (k = 0; k <= n; k++)
				{
					P[k] = 1;

					for (t = 0; t <= n; t++)
					{
						if (t != k)
						{
							P[k] = P[k] * (z[i] - x[t]) / (x[k] - x[t]);
						
						}
					}
					for (r = 0; r <= n; r++)
					{

						for (t = 0; t <= n; t++)
						{
							if (f[r] != 0)
							{
								L[t] = L[t] + f[r] * P[k];
							}
							else
							{
								L[t] = L[t];
							}

							cout << "Valoarea aproximativa a functiei f in " << z[i] << " este " << L[t] << "." << endl;

						}
						
					}	

				}
			
			}
			
		}

	}
	
	return 0;
}