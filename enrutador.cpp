#include "enrutador.h"

void enrutador::addnodo(string nodo, int costo){
    nodos.insert(pair<string,int>(nodo,costo));
}

void enrutador::removenodo(string nodo){
    nodos.erase(nodo);
}

void enrutador::modinodo(string nodo1, int newcosto){
    nodos[nodo1]=newcosto;
}

void enrutador::veonodo(){
    map<string, int>::iterator it;
    for(it=nodos.begin(); it!=nodos.end(); ++it){
        cout << it->first << " => " << it->second << '\n';
    }
}

bool enrutador::existencianodo(string name){
    if (nodos.find(name)!=nodos.end()){
        return true;
    }
    else{
        return false;
    }
}

string enrutador::creastring(string a){
    string info="";
    string principio=a;
    string num="";
    map<string, int>::iterator it;
    for(it=nodos.begin(); it!=nodos.end(); ++it){
        if (it->first == principio){
            info+=principio+principio+"I";
        }
        else{
            num=to_string(it->second);
            info+=principio+it->first+num;
        }
    }
    return info;
}

void pruebaenrutador(){
    enrutador A("A");
    A.veonodo();
    cout<<endl;
    A.addnodo("B",3);
    A.addnodo("C",6);
    A.addnodo("D",10);
    A.veonodo();
    cout<<endl;
    A.removenodo("D");
    A.modinodo("B",2);
    A.veonodo();
}
