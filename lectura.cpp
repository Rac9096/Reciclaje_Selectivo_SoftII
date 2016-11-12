#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
using namespace std;




int main(){


unordered_map <float, unordered_map<float, float>> nodos;

//--------------------------------------------------LECTURA---------------------------------------------------------------
	ifstream fin;
	string archivo= "bla.dat";
	fin.open(archivo);

    if (! fin.is_open() ){
		cout << "Error" << endl;
		exit(-1);
	}

    float x;
    float y;
    float carga;
    string tmp;

	while(true){
        
        
		getline(fin, tmp);
		stringstream flujo(tmp);
		if (fin.eof()) break;
      		while(flujo.good()){
		    flujo >> x;
		    flujo >> y;
		    flujo >> carga;
		    nodos[x][y]=carga;
      		}
		
}

/*
for(unordered_map<float, unordered_map<float, float> >::iterator ii=nodos.begin(); ii!=nodos.end(); ++ii){
	for(ii.unordered_map<float, float>::iter ia=nodos.begin(); ia!=nodos.end(); ++ia){

		cout<<ii<<" "<<ia<<" "<<nodos[ii][ia]<<endl;
	}

}*/

}
