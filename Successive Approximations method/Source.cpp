#include <iostream>
#include "g.h"
using namespace std;

int main()
{
	float x0, x1, epsilon, dif;
	int itmax;
	int it = 0;
	cout << "Introdu eroarea de calcul epsilon: "; cin >> epsilon;
	cout << "Numarul maxim de iteratii admise: "; cin >> itmax;
	cout << "Xo arbitrar: "; cin >> x0;

	do
	{
		x1 = g(x0);
		dif = fabs(x1 - x0);
		x0 = x1;
		it++;

	} while (dif >= epsilon && it <= itmax);

	if (it > itmax)
	{
		cout << "Nu se poate obtine solutia in " << itmax << " iteratii cu precizia " << epsilon << endl;
		exit(0);

	}

	cout << "Solutia obtinuta in " << it << " iteratii cu precizia " << epsilon << " este " << x1 << endl;

	return 0;


}