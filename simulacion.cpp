#include "simulacion.h"

void simulacion(){
    red distribucion;
    int menu=-1;
    string nombre="";
    string nodo1="";
    string nodo2="";
    int costo=0;
    while (menu!=5){
        cout<<endl<<"marque:\n1 para agregar un enrutador\n2 para agregar conexiones entre los enrutadores ya existentes\n3 para eliminar enrutadores\n4 para eliminar conexiones\n5 para modificar una conexion\n6 para visualizar la red completa\n7 para salir del menu\n: ";
        cin>>menu;
        if (menu==1){
            cout<<endl<<"ingrese el nombre del nuevo enrutador: ";
            cin>>nombre;
            if (distribucion.existencia(nombre)==false){
                distribucion.addenrutador(nombre);
            }
            else{
                cout<<"ese enrutador ya existe.\n";
            }
        }
        else if (menu==2){
            cout<<endl<<"ingrese el primer enrutador a emparentar: ";
            cin>>nodo1;
            cout<<endl<<"ingrese el segundo enrutador a emparentar: ";
            cin>>nodo2;
            cout<<endl<<"ingrese el costo que hay entre estos dos enrutadores: ";
            cin>>costo;
            if (distribucion.existencia(nodo1)==true && distribucion.existencia(nodo2)==true && distribucion.verdadconexion(nodo1,nodo2)==true){
                distribucion.newconexion(nodo1,nodo2,costo);
            }
            else{
                cout<<"uno de los enrutadores que se ingreso no esta en el sistema y no se puede emparentar.\n";
            }
        }
        else if (menu==3){
            cout<<endl<<"ingrese el enrutador que desea eliminar: ";
            cin>>nombre;
            if (distribucion.existencia(nombre)==true){
                distribucion.removenrutador(nombre);
            }
            else{
                cout<<"no se pudo eliminar el enrutador porque no estaba en la red.\n";
            }
        }
        else if (menu==4){
            cout<<endl<<"ingrese el primer enrutador a desemparentar: ";
            cin>>nodo1;
            cout<<endl<<"ingrese el segundo enrutador a desemparentar: ";
            cin>>nodo2;
            if (distribucion.existencia(nodo1)==true && distribucion.existencia(nodo2)==true && distribucion.verdadconexion(nodo1,nodo2)==true){
                distribucion.removeconexion(nodo1,nodo2);
            }
            else{
                cout<<"no se pudo eliminar la conexion porque o un enrutador no existe o no habia conexion previa entre los enrutadores.\n";
            }
        }
        else if (menu==5){
            cout<<endl<<"ingrese el primer enrutador a modificar: ";
            cin>>nodo1;
            cout<<endl<<"ingrese el segundo enrutador a modificar: ";
            cin>>nodo2;
            cout<<endl<<"ingrese el nuevo costo que hay entre estos dos enrutadores: ";
            cin>>costo;
            if (distribucion.existencia(nodo1)==true && distribucion.existencia(nodo2)==true && distribucion.verdadconexion(nodo1,nodo2)==true){
                distribucion.modiconexion(nodo1,nodo2,costo);
            }
            else{
                cout<<"no se pudo modificar la conexion porque o un enrutador no existe o no habia conexion previa entre los enrutadores.\n";
            }
        }
        else if(menu==6){
            distribucion.veored();
        }
        nombre="";
        nodo1="";
        nodo2="";
        costo=0;
    }
}
