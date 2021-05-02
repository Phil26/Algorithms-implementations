#include <iostream>
using namespace std;

int main()
{
	int n, i, j, k, t, m, u;
	float  x[10], f[10], z[10], N[10], s[10], p[10];

	cout << "Introdu n: "; cin >> n;

	cout << endl << "Introduceti elementele vectorului x:" << endl;
	for (i = 0; i <= n; i++)
	{
		cout << "x[" << i << "] = "; cin >> x[i];
	}

	cout << endl << "Introduceti elementele vectorului f: " << endl;
	for (j = 0; j <= n; j++)
	{
		cout << "f[" << j << "] = "; cin >> f[j];
	}

	cout << endl << "Introduceti dimensiunea lui z: "; cin >> m;
	for (t = 0; t <= m; t++)
	{
		cout << "z[" << t << "] = "; cin >> z[t];
	}

	for (i = 0; i <= n; i++)
	{
		for(j = 0; j <= m; j++)
		{ 

		if (z[j] < x[0] || z[j] > x[n])
		{
			cout << "Nu putem aproxima f in z["<< j <<"] = " << z[j] << ". Nu apartine intervalului stabilit." <<  endl;
			exit(0);
		}

		else if (z[j] == x[i])
		{
			cout << "Valoarea lui f in z["<< j <<"] = " << z[j] << " este f[" << i << "] = " << f[i] << "." << endl;
			exit(0);
		}

		else
		{
			for(t = 0; t <= n; t++)
			N[t] = f[i];

			for (k = 1; k <= n; k++)
			{
				s[k] = 0;

				for (u = 0; u <= k; u++)
				{
					p[u] = 1;

						if (i != j)
						{
							p[u] = p[u] * (x[j] - x[i]);
						}
				}

					s[k] = s[k] + f[j] / p[u];
			}

					p[u] = 1;

					
						p[u] = p[u] * (z[j] - x[i]);
					

					N[t] = N[t] + s[k] * p[u];

		}

	}

	}

     cout << "Valoarea aproximativa a functiei f in " << z[j] << " este " << N[t] << "." << endl;
	
	return 0;

}