#include "biblios.h"


void Recorrer_Ruta(unordered_map<int, unordered_map<int,int>> ruta, int cant_visit)
{
	//RECORRE RUTA
	for(int i = 0; i < cant_visit; i++)
	{
		for (int j = 0; j < cant_visit; j++)
		{
			cout<<ruta[i][j] << endl;
		}
	}
}



int Calcular_min_z(m_c m, int c_clientes, int K, int H)//(rutas a, rutas b, rutas etc)
{
    int z=0;
    for(int i=0; i<c_clientes; i++)
    {
        for(int j=0; j<c_clientes; j++)
        {
            for(int k=0; k<K; k++)
            {
                for(int l=0; l<H; l++)
                {
                    z = z+m[i][j].x[k][l]*m[i][j].costo;
                }
            }
        }
    }
    return z;
}


unordered_map<int, Cliente> Guardar_Clientes() //ok
{
	unordered_map<int, Cliente> cl;
	ifstream fin;
	int c_clientes, c_pto_aco, c_vehi;
	int x, y, carga;
	int i=0;
	string archivo= "clientes.dat";
	fin.open(archivo);

    if (! fin.is_open() )
    {
		cout << "Error" << endl;
		exit(-1);
	}
	string tmp;
	getline(fin, tmp);
	stringstream flujo(tmp);
	flujo >> c_clientes;
	flujo >> c_pto_aco;
	flujo >> c_vehi;
	C_CLIENTES = c_clientes;
	C_PTO_ACO = c_pto_aco;
	C_VEHI = c_vehi;//guardan en variables globales 
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
      			cl[i].id = i;
      			cl[i].x = x;
      			cl[i].y = y;
      			cl[i].oferta = carga;
      			i++;
      		}
	}
return cl;
}

unordered_map <int, Deposito> Guardar_Depositos() //ok
{
	unordered_map <int,Deposito> dep;
	ifstream fin;
	int x, y, oi, c_depos;
	int i=0;
	string archivo= "depositos.dat";
	fin.open(archivo);

    if (! fin.is_open() )
    {
		cout << "Error" << endl;
		exit(-1);
	}
	string tmp;
	getline(fin, tmp);
	stringstream flujo(tmp);
	flujo >> c_depos;
	C_DEPO=c_depos;


	while(true)
	{
		getline(fin, tmp);
		stringstream flujo(tmp);

		if (fin.eof()) break;
      		while(flujo.good())
      		{	
      			flujo >> x;
      			flujo >> y;
      			flujo >> oi;
      			dep[i].id = i+C_CLIENTES+100;
      			dep[i].x = x;
      			dep[i].y = y;
      			dep[i].Oi = oi;
      			i++;
      		}

	}

return dep;
}


m_c Leer_deposito(unordered_map<int, Cliente> cl, unordered_map<int, Deposito> dep)
{

	m_c m_costo;
    //MATRIZ DE COSTO
	for(int i=0; i<C_DEPO; i++)
	{
		for(int j=0; j<C_CLIENTES; j++)
		{
			int delta_x_2 = pow((cl[i].x - dep[j].x),2);
			int delta_y_2 = pow((cl[i].y - dep[j].y),2);
			int res = ((delta_y_2 + delta_x_2));
            m_costo[i][j].costo = res;
		}
	}
	return m_costo;
}


m_c Leer_Cliente(unordered_map <int, Cliente> clientes)
{
	int c_clientes = C_CLIENTES;
    //MAPA DE GRAFO (FUNCIONAAAAAA!!!)
    m_c m_costo;
  /*  m_costo_2[0][0].costo = 2;
    m_costo_2[0][0].x[0][0] = 1;
    cout << m_costo_2[0][0].costo << endl;
    cout << m_costo_2[0][0].x[0][0] << endl;*/
    int K = 3;
    int H = 5;

    //MATRIZ DE COSTO
	for(int i=0; i<c_clientes; i++)
	{
		for(int j=0; j<c_clientes; j++)
		{
			int delta_x_2 = pow((clientes[i].x - clientes[j].x),2);
			int delta_y_2 = pow((clientes[i].y - clientes[j].y),2);
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
	return m_costo;
}







unordered_map <int, Cliente> ASIGNACION(unordered_map <int, Deposito> dep, unordered_map <int, Cliente> clie)
{
	int c_clientes=C_CLIENTES;
	int c_depos=C_DEPO;

	int aux=0;
	int d_menor=0;
	for(int j=0; j< c_clientes; j++)
	{
		for(int i=0; i< c_depos; i++)
		{

				int delta_x_2 = pow((clie[j].x - dep[i].x),2);
				int delta_y_2 = pow((clie[j].y - dep[i].y),2);
				int res = ((delta_y_2 + delta_x_2));

				if (i == 0)
				{
					d_menor	= res;
					aux = dep[i].id;
				}
				else if (res < d_menor)
				{
					d_menor = res;
					aux = dep[i].id;
				}

		}
		clie[j].id_deposito = aux;
	}
return clie;
}
	

void Comb()
{

}

/*
void Generar_Texto_tsp(unordered_map <int, Deposito> dep, unordered_map <int, Cliente> cl, string salida)
{
	ofstream out(salida); //out escribe en el archivo con nombre salida
	for(int i=0; i < C_CLIENTES; i++)
	{	
			out << cl[i].id << "\t" << cl[i].x << "\t" << cl[i].y << endl;
	}
}

*/

unordered_map<int, int> leer_tsp() //ok
{

	unordered_map <int, int> tsp;
	ifstream fin;
	int id_nodo;
	int i=0;
	string archivo= "mysolution.txt";
	fin.open(archivo);

    if (! fin.is_open() )
    {
		cout << "Error" << endl;
		exit(-1);
	}
	string tmp;
	getline(fin, tmp);
	stringstream flujo(tmp);
	flujo >> id_nodo;


	while(true)
	{
		getline(fin, tmp);
		stringstream flujo(tmp);

		if (fin.eof()) break;
      		while(flujo.good())
      		{	
      			flujo >> id_nodo;
      			tsp[i]= id_nodo-1;
      			i++;
      		}
	}



return tsp;


}






void generar_ruta(int k, unordered_map <int, Cliente> cl, unordered_map <int, Deposito> dep)
{
	int id_nodo;
	//vector<list<int> > ruta;
	//unordered_map<int, int> tsp;
	unordered_map <int, vector<int> > ruta;//solucion parche
	unordered_map<int, int> tsp;
	tsp=leer_tsp();

	for(int i=0; i < C_CLIENTES; i++)
	{
		id_nodo = tsp[i];
		ruta[cl[id_nodo].id_deposito].push_back(id_nodo);
	}

	for(int i=0; i < C_CLIENTES; i++)
	{
		id_nodo = tsp[i];
		ruta[cl[id_nodo].id_deposito].push_back(id_nodo);
	}



	int jj=0;

cout << endl;
	for(unordered_map<int, vector<int> >::iterator ii=ruta.begin(); ii!=ruta.end(); ii++){
    	vector <int> inVect = (*ii).second;
  
    	int tamano=inVect.size()/2;
    	for(int j=0; j<tamano; j++)
    	{
    			if(jj==0)
    			{
    				cout << (*ii).first << "\t";
    				jj++;

    			}
    			if(jj<=k)
    			{

    				cout<<inVect[j]<<"\t";
    				jj++;
    			}

    			if(jj>k || j==tamano-1)
    			{
    				cout << (*ii).first << endl;
    				jj=0;
    			}
     	}	
     	cout << endl;
     	jj=0;
    }

}





int main()
{
//--------------------------------------------------LECTURA---------------------------------------------------------------
	m_c m_costo;
	m_c m_costo2;
	unordered_map <int, Cliente> cl;
	unordered_map <int, Deposito> dep;
	unordered_map<int, int> tsp;
	cl = Guardar_Clientes();
	dep = Guardar_Depositos();
	m_costo = Leer_Cliente(cl);
	m_costo2 = Leer_deposito(cl, dep);
	cl = ASIGNACION(dep, cl);

	int k=3;	//cantidad de visitas por rutas
	generar_ruta(k, cl, dep);


/*
for(int i=0; i<C_CLIENTES;i++){


	cout<< cl[i].id<<"\t"<<cl[i].id_deposito<<endl;





}

for(int i=0; i<C_DEPO;i++){


	cout<< dep[i].id<<endl;





}*/
/*
vector<list<int> > ruta;
vector<list<int> >::iterator ii=ruta.begin();
list <int> inlist = (*ii).begin();

for(int i=0; i<8; i++)
{
	for(int j=0; j<8; j++)
	{
		
	

	}
	

}*/







}