#ifndef ENRUTADOR_H
#define ENRUTADOR_H
#include <iostream>
#include <string>;
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <limits.h>
#include <climits>
#include <algorithm>

using namespace std;


class enrutador{
    map<string, int> nodos;
    public:
        enrutador(){}
        enrutador(string nodo){
            nodos.insert(pair<string,int>(nodo,0));
        }
        void addnodo(string nodo,int costo);
        void removenodo(string nodo);
        void modinodo(string nodo, int newcosto);
        void veonodo();
        bool existencianodo(string name);
        string creastring(string a);
};

void pruebaenrutador();

#endif // ENRUTADOR_H
