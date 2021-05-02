#ifndef MATRICE_H_
#define MATRICE_H_
#include <iostream>
using namespace std;


class Cmatrix {

	int n; 
	float **matrix;

public:

	Cmatrix() {

		float val;
		cout << "Dimensiunea matricelor: ";
		cin >> n;
    
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << "matrix[" << i << "][" << j << "] = ";
				cin >> val;
				matrix[i][j] = val;
			}
		}
	}
	
	Cmatrix(int dimensiune) : n(dimensiune) {
		int i, j;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				cout << "matrix["<< i <<"]["<< j <<"] = ";
				cin >> matrix[i][j];
			}
		}
		
	}
	
	~Cmatrix() {

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix[i][j] = 0;
			}

		}
	cout << "S-a apelat destructorul clasei matrix" << endl;

	}

	void read(int n);
	void display(int n);
	int get_n()
	{
		return this->n;
	}
    
	void set_n()
	{
		int val;
		cout << "Set n: ";
		cin >> val;
		this->n = val;
	}

	Cmatrix operatia1(Cmatrix matrice);
	Cmatrix operatia2();
	Cmatrix operatia3(Cmatrix matrice);
	Cmatrix operatia4(Cmatrix matrice);
	Cmatrix operatia5(Cmatrix matrice);
	void interchange_lines(int line1, int line2);
	float suma_urma();
};
	

#endif // MATRICE_H_ 

