#include "red.h"

void red::addenrutador(string name){
    enrutadores.insert({name, enrutador(name)});
}

string red::newconexion(string a, string b, int costo){
    enrutadores[a].addnodo(b,costo);
    enrutadores[b].addnodo(a,costo);
    int i=0;
    int j=0;
    int con=0;
    string numero="";
    map<string, enrutador>::iterator ite;
    for(ite=enrutadores.begin(); ite!=enrutadores.end(); ++ite){
        con++;
        if (ite->first==a){
            i=con-1;
            break;
        }
    }
    con=0;
    map<string, enrutador>::iterator it;
    for(ite=enrutadores.begin(); it!=enrutadores.end(); ++it){
        con++;
        if (ite->first==b){
            j=con-1;
            break;
        }
    }
    string is=to_string(i);
    string js=to_string(j);
    numero+=is+','+js;
    return numero;
}

string red::modiconexion(string a, string b, int newcosto){
    enrutadores[a].modinodo(b,newcosto);
    enrutadores[b].modinodo(a,newcosto);
    int i=0;
    int j=0;
    int con=0;
    string numero="";
    map<string, enrutador>::iterator ite;
    for(ite=enrutadores.begin(); ite!=enrutadores.end(); ++ite){
        con++;
        if (ite->first==a){
            i=con-1;
            break;
        }
    }
    con=0;
    map<string, enrutador>::iterator it;
    for(ite=enrutadores.begin(); it!=enrutadores.end(); ++it){
        con++;
        if (ite->first==b){
            j=con-1;
            break;
        }
    }
    string is=to_string(i);
    string js=to_string(j);
    numero+=is+','+js;
    return numero;
}

void red::removeconexion(string a, string b){
    enrutadores[a].removenodo(b);
    enrutadores[b].removenodo(a);
}

void red::removenrutador(string name){
    enrutadores.erase(name);
    map<string, enrutador>::iterator ite;
    for(ite=enrutadores.begin(); ite!=enrutadores.end(); ++ite){
        ite->second.removenodo(name);
    }
}

void red::veored(){
    map<string, enrutador>::iterator ite;
    for(ite=enrutadores.begin(); ite!=enrutadores.end(); ++ite){
        ite->second.veonodo();
        cout<<endl;
    }
}

bool red::existencia(string name){
    if (enrutadores.find(name)!=enrutadores.end()){
        return true;
    }
    else{
        return false;
    }
}

bool red::verdadconexion(string a, string b){
    if (enrutadores[a].existencianodo(b)==true){
        return true;
    }
    else{
        return false;
    }
}


void pruebared(){
    red barbosa;
    barbosa.addenrutador("A");
    barbosa.addenrutador("B");
    barbosa.addenrutador("C");
    barbosa.addenrutador("D");
    //barbosa.veored();
    //cout<<endl;
    barbosa.newconexion("A","B",2);
    barbosa.newconexion("A","C",6);
    barbosa.newconexion("C","D",7);
    barbosa.newconexion("C","B",1);
    barbosa.veored();
    cout<<endl;
    barbosa.removenrutador("C");
    barbosa.veored();
}
