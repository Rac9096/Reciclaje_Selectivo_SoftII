#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;




int main(){




//--------------------------------------------------LECTURA---------------------------------------------------------------
	ifstream fin;
	string archivo= "PLRP1coord20-5-1.dat";
	fin.open(archivo);

    if (! fin.is_open() ){
		cout << "Error" << endl;
		exit(-1);
	}

    float palabra;
    string tmp;

	while(true){
        
        
		getline(fin, tmp);
		stringstream flujo(tmp);
		if (fin.eof()) break;
      		while(flujo.good()){
		    flujo >> palabra;
		    cout<<" "<< palabra;
      		}
      		cout<<endl;
		
}







}
