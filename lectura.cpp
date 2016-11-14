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

int main(){


unordered_map <int, unordered_map<int, int>> nodos;
v_chico v1;
v_grande mc;

int n=1;
int m=20;
int coordenadas[n][m];


//--------------------------------------------------LECTURA---------------------------------------------------------------
	ifstream fin;
	string archivo= "bla.dat";
	fin.open(archivo);

    if (! fin.is_open() ){
		cout << "Error" << endl;
		exit(-1);
	}

    int x;
    int y;
    int carga;
    string tmp;

    int j=0;
	while(true){
        
 		
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
         	coordenadas[0][j] = x;
		    coordenadas[1][j] = y;
		    cout << coordenadas[0][j] << "\t" << coordenadas[1][j] << endl;
			
			j++;

}


}
