#include <iostream>
using namespace std;

int main()
{

	float A[10][10], a[10], b[10], c[10], t[10];
	int n, i, j;
	cout << "Dimensiunea matricei A:"; cin >> n;


	for (i = 1; i <= n; i++)
	{
		cout << "a[" << i << "] = "; cin >> a[i];
	}

	for (i = 1; i <= (n - 1); i++)
	{
		cout << "b[" << i << "] = "; cin >> b[i];
	}

	for (i = 1; i <= (n - 1); i++)
	{
		cout << "c[" << i << "] = "; cin >> c[i];
	}

	cout << "Elementele termenului liber sunt: " << endl;

	for (i = 1; i <= n; i++)
	{
		cout << "t[" << i << "] = "; cin >> t[i];
	}


	for (i = 1; i <= (n - 1); i++)
	{
		if (a[i] == 0)
		{
			cout << "Sistemul nu are solutie unica deoarece avem elementul diagonal nul in linia " << i << "." << endl;
			return -1;
		}

		c[i] = c[i] / a[i];
		a[i + 1] = a[i + 1] - b[i] * c[i];

	}

	for (i = 2; i <= n; i++)
	{
		t[i] = t[i] - c[i - 1] * t[i - 1];
	}

	if (a[n] == 0)
	{
		cout << "Sist. nu are solutie unica deoarece avem elementul diagonal nul in linia " << n << endl;
		return -1;
	}

	t[n] = t[n] / a[n];
	
	for (i = (n - 1); i >= 1; i--)
	{
		t[i] = (t[i] - b[i] * t[i + 1]) / a[i];
	}
	
	for (i = 1; i <= n; i++)
	{
		cout << endl << "x[" << i << "] = " << t[i] << endl;
	}

	return 0;

}