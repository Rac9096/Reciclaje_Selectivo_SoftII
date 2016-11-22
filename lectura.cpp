#include "biblios.h"





int main()
{

	int m=2;
	vector<pair<int,int>> ruta;
	//ruta[i].first
	//ruta[i].second
//--------------------------------------------------LECTURA---------------------------------------------------------------
	ifstream fin;
	string archivo= "bla.dat";
	fin.open(archivo);

    if (! fin.is_open() )
    {
		cout << "Error" << endl;
		exit(-1);
	}

	int c_depos;
	int c_pto_aco;
	int c_vehi;
    int x;
    int y;
    int carga;
    string tmp;

    int i=1;

	getline(fin, tmp);
	stringstream flujo(tmp);
	flujo >> c_depos;
	flujo >> c_pto_aco;
	flujo >> c_vehi;
    int coordenadas[c_depos+1][m];
    Grafo m_costo[c_depos+1][c_depos+1];
    //typedef unordered_map<int, Grafo> estruct;
    //unordered_map<int, estruct> m_costo;
    int medx = 0;
	int medy = 0;
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
				

      		}

      				coordenadas[i][0] = x;
		      		coordenadas[i][1] = y;
		      		medx = x + medx;
		      		medy = y + medy;
					i++;
	}
	medx = medx/c_depos;
	medy = medy/c_depos;
	coordenadas[0][0] = medx;
	coordenadas[0][1] = medy;

cout << endl << endl << endl;

cout <<c_depos<<endl;
cout <<c_vehi<<endl;
cout <<c_pto_aco<<endl;

int K = 3;
int H = 5;

//matriz de costo
	for(int i=0; i<c_depos+1; i++)
	{
		for(int j=0; j<c_depos+1; j++)
		{
			int delta_x_2 = pow((coordenadas[i][0] - coordenadas[j][0]),2);
			int delta_y_2 = pow((coordenadas[i][1] - coordenadas[j][1]),2);
			int res = ((delta_y_2 + delta_x_2));
            m_costo[i][j].costo = res;
            for(int k=0; k<K; k++)
            {
                for(int l=0; l<H; l++)
                {
                    m_costo[i][j].x[k][l]=0;
                }
            }
		}
	}
	int menor = 10000000;

	
//------------------------------ENCONTRAR RUTA---------------------

	int cant_visit=5;


	int visit=0;
	int c=0; int k=1;
	int paseo=1;
	cout<<"llegue aca"<<endl;
	vector<int> v;
	int c_menor=0;

	pair <int, int> par;
	int c1,c2;
	int visitado[c_depos];
	for(int i=0; i<c_depos; i++)
	{
		visitado[i]=0;
	}

while(visit<cant_visit)
{
	
	while(paseo<c_depos+1)
	{
		
		if(visitado[k]!=1)
		{

			if((m_costo[c][k].costo)<=menor)
			{
				menor=(m_costo[c][k].costo);
				c_menor=k;
				k++;
			
			}
			else
			{
				k++;

			}

		}
		else{
			k++;
		}
				paseo++;
	}
		c1 = coordenadas[c_menor][0];
		c2 = coordenadas[c_menor][1];
			visitado[c_menor]=1;
			par = make_pair(c1, c2);
			ruta.push_back(par);
			visit++;
			c=c_menor;
			k=1;
			c_menor=0;
			paseo=0;
			menor=10000000;

}

for(int i = 0 ;i < 5 ; i++)
{
	cout << ruta[i].first<< " "<< ruta[i].second <<  endl; 

}








}





