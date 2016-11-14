#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


typedef vector <float> v_chico;
typedef	vector <v_chico> v_grande;

int main()
{

	unordered_map <int, unordered_map<int, int>> nodos;
	v_chico v1;
	v_grande mc;

	int m_costo[20][20];

	int n=20;
	int m=2;
	int coordenadas[n][m];


//--------------------------------------------------LECTURA---------------------------------------------------------------
	ifstream fin;
	string archivo= "bla.dat";
	fin.open(archivo);

    if (! fin.is_open() )
    {
		cout << "Error" << endl;
		exit(-1);
	}

    int x;
    int y;
    int carga;
    string tmp;

    int i=0;


    // mapa de coordenadas + carga // y coordenadas
	while(true)
	{
        
 		
		getline(fin, tmp);
		stringstream flujo(tmp);
		if (fin.eof()) break;

      		while(flujo.good())
      		{
			 
			    flujo >> x;
			    flujo >> y;
			    flujo >> carga;
			    nodos[x][y]=carga;

      		}
			   coordenadas[i][0] = x;
		       coordenadas[i][1] = y;
			i++;
	}


cout << endl << endl << endl;

//matriz de costos
	for(int i=0; i<20; i++)
	{
		for(int j=0; j<20; j++)
		{
			int delta_x_2 = (coordenadas[i][0] - coordenadas[j][0])*(coordenadas[i][0] - coordenadas[j][0]);
			int delta_y_2 = (coordenadas[i][1] - coordenadas[j][1])*(coordenadas[i][1] - coordenadas[j][1]);
			int res = delta_y_2 + delta_x_2;
			m_costo[i][j] = res;
			cout << m_costo[i][j] << "\t";
		}
		cout << endl;
	}
}