#include<iostream>
#include<conio.h>
#include <math.h>
using namespace std;

int main() 
{
    float a[10][10], b[10], x[10], y[10], max = 0, epsilon;
    int n, it, i, j, itmax;

    cout << "Dimensiune matrice : ";
    cin >> n;

    cout << "Elementele matricei: " << endl;
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
    cout << "\nElemente termen liber\n";
    for (i = 0; i < n; i++) {
        cout << "b[" << i << "] = ";
        cin >> b[i];
    }
    cout << "Valori arbitrare solutie:\n";
    for (i = 0; i < n; i++) 
    {
        x[i] = 0;
        cout << "x[" << i << "] = " << x[i] << endl;
    }

    cout << "Eroare admisa: "; cin >> epsilon;

    cout << "Numar maxim iteratii: "; cin >> itmax;
    it = 1;
    
    do
    {   
        cout << "\nIteratia numarul " << it << endl;
        cout << "Solutii:" << endl;
     
            for (i = 0; i < n; i++) 
            {
                y[i] = (b[i] / a[i][i]);
                for (j = 0; j < n; j++) 
                {
                    if (j == i)
                        continue;
                    y[i] = y[i] - ((a[i][j] / a[i][i]) * x[j]);
                    if (max < fabs(y[i] - x[i]))
                    {
                        max = fabs(y[i] - x[i]);
                    }
                  
                }
                x[i] = y[i];
               
                cout << "x[" << i << "] =" << x[i] << endl;
            }
            cout << "\n";
            it++;

    }
    while (max > epsilon && it <= itmax);
       
    return 0;
    }