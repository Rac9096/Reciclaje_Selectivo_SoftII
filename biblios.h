#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;

typedef unordered_map<int, int> mp;

typedef struct grafo
{
  int costo;
  unordered_map<int, mp> x;
}Grafo;


