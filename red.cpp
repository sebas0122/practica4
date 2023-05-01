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
    map<string, enrutador>::iterator ite;
    for(ite=enrutadores.begin(); ite!=enrutadores.end(); ++ite){
        parcial=ite->second.creastring();
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
    map<string, enrutador>::iterator ete;
    for(ete=enrutadores.begin();ete!=enrutadores.end();ete++){
       con2++;
       if(ete->first==nodoi){
        s=con2-1;
       }
       else if(ete->first==nodof){
           t=con2-1;
       }
    }
    con2=0;
    int lon=enrutadores.size();
    int matriz[lon][lon];
    for (int i=0;i<lon;i++){
        for (int j=0;j<lon;j++){
            matriz[i][j]=-1;
        }
    }
    int con=0;
    con2=0;
    int a=0;
    int b=0;
    int c=0;
    string pa="";
    for (int i=0;i<letras.length();i++){
        con++;
        pa=letras[i];
        if (con==1){
            map<string, enrutador>::iterator ti;
            for(ti=enrutadores.begin();ti!=enrutadores.end();ti++){
               con2++;
               if(ti->first==pa){
                a=con2-1;
                con2=0;
               }
            }
        }
        else if(con==2){
            map<string, enrutador>::iterator ti;
            for(ti=enrutadores.begin();ti!=enrutadores.end();ti++){
                con2++;

                if(ti->first==pa){
                 b=con2-1;
                 con2=0;
                }
            }
        }
        else if(con==3){
            c=stoi(pa);
        }
        matriz[a][b]=c;
        a=0;
        b=0;
        c=0;
        con=0;
        con2=0;
    }
    vector<int> dist;
    vector<int> prev(lon, -1);
    typedef pair<int, int> pii;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist.resize(lon, 100000); // Inicializar distancias como infinito
    dist[s] = 0; // La distancia desde el nodo de inicio a sí mismo es 0
    pq.push(make_pair(0, s)); // Agregar el nodo de inicio a la cola de prioridad
    prev.resize(lon, -1); // Inicializar nodos predecesores con -1

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < lon; v++) {
            if (matriz[u][v] != -1) { // Si hay una arista entre u y v
                int w = matriz[u][v];
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    prev[v] = u; // Actualizar nodo predecesor en camino mínimo
                    pq.push(make_pair(-dist[v], v));
                }
            }
        }
    }

    // Construir camino mínimo desde t hasta s
    vector<int> path;
    int u = t;
    while (u != -1) {
        path.insert(path.begin(), u);
        u = prev[u];
    }
    // Imprimir camino mínimo
    cout << "Camino mínimo desde " << s << " hasta " << t << ": ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
    cout<<"y el valor es de: "<<dist[t];
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
    string letras=barbosa.creatring2();
    barbosa.caminos(letras,"A","D");
}
