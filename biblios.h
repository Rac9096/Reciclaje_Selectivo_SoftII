#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <list>
using namespace std;

typedef unordered_map<int, int> mp;

typedef struct grafo
{
  int costo;
  unordered_map<int, mp> x;
}Grafo;

typedef	struct clientes
{
  int id;
  int x;
  int y;
 // unordered_map<int, int> djlr; // oferta del cliente // se busca con id en vector de clintes, el dia l del horizonte H, y la ruta r de la combinacion de dias Comb
  int oferta;
  int id_deposito; //deposito que atendera al cliente i (id)
}Cliente;


typedef	struct vehiculo
{
	int id;
	int Qi;
}Vehiculo;


typedef	struct deposito
{
	int id;
	int x;
	int y;
	//int Wi; //Capacidad del deposito
	int Oi; //Costo de apertura
	int yi; //Binario, abierto o cerrado
}Deposito;



int C_CLIENTES, C_PTO_ACO, C_VEHI, C_DEPO, Q, F;

typedef	unordered_map<int, unordered_map<int, Grafo>> m_c;
