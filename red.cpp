#include "red.h"

void red::addenrutador(string name){
    enrutadores.insert({name, enrutador(name)});
}

void red::newconexion(string a, string b, int costo){
    enrutadores[a].addnodo(b,costo);
    enrutadores[b].addnodo(a,costo);
}

void red::modiconexion(string a, string b, int newcosto){
    enrutadores[a].modinodo(b,newcosto);
    enrutadores[b].modinodo(a,newcosto);
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

string red::creatring2(){
    string conexiones="";
    string parcial="";
    string parametro="";
    map<string, enrutador>::iterator ite;
    for(ite=enrutadores.begin(); ite!=enrutadores.end(); ++ite){
        parametro=ite->first;
        parcial=ite->second.creastring(parametro);
        conexiones+=parcial;
    }
    return conexiones;
}

int red::sizeenru(){
    int size=enrutadores.size();
    return size;
}

void red::caminos(string letras,string nodoi,string nodof){
    int con2=0;
    int s=0;
    int t=0;
    int indice=0;
    string nodos="";
    string nodo="";
    map<string, enrutador>::iterator ete;
    for(ete=enrutadores.begin();ete!=enrutadores.end();ete++){
        nodo=ete->first;
        nodos+=nodo;
    }
    string tu="";
    for (int i=0;i<nodos.size();i++){
        tu=nodos[i];
        if(nodoi==tu){
            s=i;
        }
        else if(tu==nodof){
            t=i;
        }
    }
    int lon=enrutadores.size();
    int matriz[lon][lon]={};
    for (int i=0;i<lon;i++){
        for (int j=0;j<lon;j++){
            matriz[i][j]=-1;
        }
    }
    int con=0;
    int a=0;
    int b=0;
    int c=0;
    string control="I";
    string pa="";
    string ind="";
    string num="";
    for (int i=0;i<letras.size();i++){
        con++;
        pa=letras[i];
        while(letras[i+1]>=48 && letras[i+1]<=57 && con==3){
            i++;
            pa+=letras[i];
        }
        if (con==1){
            for(int j=0;j<nodos.size();j++){
                ind=nodos[j];
                if(ind==pa){
                    a=j;
                    break;
                }
            }
        }
        else if(con==2){
            for(int k=0;k<nodos.size();k++){
                ind=nodos[k];
                if(ind==pa){
                    b=k;
                    break;
                }
            }
        }
        else if(con==3){
            if (pa==control){
                c=-1;
                matriz[a][b]=c;
            }
            else{
                c=stoi(pa);
                matriz[a][b]=c;
            }
            a=0;
            b=0;
            c=0;
            con=0;
            con2=0;
            pa="";
        }
    }
    int distancia[lon], anterior[lon];
        bool visitado[lon] = {false};

        for (int i = 0; i < lon; i++) {
            distancia[i] = INT_MAX;
            anterior[i] = -1;
        }

        distancia[s] = 0;

        for (int i = 0; i < lon - 1; i++) {
            int u = -1;
            for (int j = 0; j < lon; j++) {
                if (!visitado[j] && (u == -1 || distancia[j] < distancia[u])) {
                    u = j;
                }
            }
            visitado[u] = true;

            for (int v = 0; v < lon; v++) {
                int peso = matriz[u][v];
                if (peso != -1 && distancia[u] + peso < distancia[v]) {
                    distancia[v] = distancia[u] + peso;
                    anterior[v] = u;
                }
            }
        }

        if (distancia[t] == INT_MAX) {
            cout << "No hay camino desde " << nodoi << " hasta " << nodof << endl;
        }
        else {
            cout << "Camino mínimo desde " << nodoi << " hasta " << nodof << ": ";
            vector<int> camino;
            for (int v = t; v != -1; v = anterior[v]) {
                camino.push_back(v);
            }
            reverse(camino.begin(), camino.end());
            string l="";
            for (int v : camino) {
                l=nodos[v];
                cout << l << " ";
            }
            cout << endl;
            cout << "Costo: " << distancia[t] << endl;
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
    barbosa.newconexion("B","D",9);
    barbosa.veored();
    cout<<endl;
    barbosa.removenrutador("C");
    barbosa.veored();
    int df=barbosa.sizeenru();
    string letras=barbosa.creatring2();
    df=letras.size();
    barbosa.caminos(letras,"A","D");
}
