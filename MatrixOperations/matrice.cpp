#include "matrice.h"

void Cmatrix::display(int n) 
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j];
			cout << endl;
		}
	}
}

void Cmatrix::read(int n)
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "matrice[" << i << "][" << j << "] = ";
			cin >> matrix[i][j];
		}
	}
}


Cmatrix Cmatrix::operatia1(Cmatrix matrice) 
{
	Cmatrix rezultat;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			rezultat.matrix[i][j] += rezultat.matrix[i][j] - 2 * matrice.matrix[i][j];
		}
	}

	return rezultat;

}


Cmatrix Cmatrix::operatia2()
{
	Cmatrix rezultat;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{

				rezultat.matrix[i][j] += matrix[i][k] * matrix[k][j];
			}
		}

	}

	return rezultat;
}

Cmatrix Cmatrix::operatia3(Cmatrix matrice)
{
	Cmatrix rezultat;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; i++)
		{
			for (int k = 0; k < n; k++)
			{
				rezultat.matrix[i][j] += matrice.matrix[i][k] * matrix[k][j];
			}
		}
	}

	return rezultat;
}


Cmatrix Cmatrix::operatia4(Cmatrix matrice)
{
	Cmatrix rezultat;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; i++)
		{
			for (int k = 0; k < n; k++)
			{
				rezultat.matrix[i][j] += matrix[i][k] * matrice.matrix[k][j];
			}
		}
	}

	return rezultat;
}

Cmatrix Cmatrix::operatia5(Cmatrix matrice)
{
	Cmatrix rezultat;
	Cmatrix matrice_unitate;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; i++)
		{
			rezultat.matrix[i][j] += matrix[i][j] + 2 * matrice_unitate.matrix[i][j];
		}

	}

	return rezultat;
}

void Cmatrix:: interchange_lines(int line1, int line2)
{
	float aux[10];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			aux[i] = matrix[2][j];
			matrix[2][j] = matrix[3][j];
			matrix[3][j] = aux[i];

		}
	}

	this->display(n);

}

float Cmatrix::suma_urma() {
	
	float suma = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
			suma += matrix[i][j];
			}
		}
	}

	return suma;
}





