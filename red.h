#ifndef RED_H
#define RED_H
#include "enrutador.h"
using namespace std;

class red{
    map<string,enrutador> enrutadores;
public:
    red(){}
    void addenrutador(string name);
    void newconexion(string a,string b,int costo);
    void removenrutador(string name);
    void removeconexion(string a,string b);
    void modiconexion(string a,string b,int newcosto);
    void veored();
    bool existencia(string name);
    bool verdadconexion(string a, string b);
    string creatring2();
    int sizeenru();
    void caminos(string letras,string nodoi,string nodof);
};
void pruebared();

#endif // RED_H
