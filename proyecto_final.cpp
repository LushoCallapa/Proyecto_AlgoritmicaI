#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
vector<vector<int> > rutas(30);
vector<vector<int> > historial;
int visitados[30],nivel[30],camino[30];
vector<int> bfs(int nodoInicial, int destino){
    nivel[nodoInicial] = 0;
    visitados[nodoInicial] = 1;
    queue<int> colaNodos;
    colaNodos.push(nodoInicial);
    while(!colaNodos.empty()){
        int nodoActual = colaNodos.front();
        colaNodos.pop();
        for(int i=0;i<rutas[nodoActual].size();i++){
            if(!visitados[rutas[nodoActual][i]]){
                visitados[rutas[nodoActual][i]] = 1;
                nivel[rutas[nodoActual][i]] = nivel[nodoActual]+ 1;
                colaNodos.push(rutas[nodoActual][i]);
                camino[rutas[nodoActual][i]] = nodoActual;
            }
        }

    }
    vector<int> ruta;
    for (int nodo= destino; nodo != -1; nodo = camino[nodo]) {
        ruta.push_back(nodo);
    }
    reverse(ruta.begin(), ruta.end());
    return ruta;
}
void unionRutas(){
    rutas[0]={1,3,4,10};
    rutas[1]={0,2,6,3,10};
    rutas[2]={4,6,9,5};
    rutas[3]={0,2,4,6};
    rutas[4]={2,9,6,3};
    rutas[5]={1,5,6,7,10};
    rutas[6]={0,7,6};
    rutas[7]={3,6,9,8};
    rutas[8]={0,4,5,7,2};
    rutas[9]={8,5,2,6,0};
    rutas[10]={1,5,7,8,9};
}
int main()
{
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );

    int opcion;
    unionRutas();
    SetConsoleTextAttribute(hConsole, 2);
    cout<<"=====================\n";
    SetConsoleTextAttribute(hConsole, 4);
    cout<<"|  Opcion 1: Rutas  |\n";
    cout<<"|Opcion 2: Historial|\n";
    cout<<"|  Opcion 3: Salir  |\n";
    SetConsoleTextAttribute(hConsole, 2);
    cout<<"=====================\n";
    SetConsoleTextAttribute(hConsole, 3);
    cout<<"Seleccione una opcion: ";
    while(cin>>opcion, opcion !=3){
        if(opcion==1){
            int destino;
            memset(visitados,0,sizeof(visitados));
            memset(camino,-1,sizeof(camino));
            cout<<"Ha que lugar desea llegar: ";
            scanf("%d",&destino);
            if(destino<=0 and destino>10){
                cout<<"Destino no valido\n";
            }
            else{
                vector<int> ruta = bfs(0,destino);
                if(visitados[destino]){
                    for(int i=0;i<ruta.size()-1;i++)
                        cout<<ruta[i]<<"->";
                    cout<<ruta[ruta.size()-1]<<endl;
                    if(historial.size()==5){
                        for(int i=0;i<4;i++){
                            historial[i]=historial[i+1];
                            }
                        historial[4]=ruta;
                    }
                    else{
                        historial.push_back(ruta);
                    }
                }
                else{
                    cout<<"No existe un camino"<<endl;
                }

            }

        }
        else if(opcion==2){
            for(int i=0;i<historial.size();i++){
                cout<<i+1<<".- ";
                for(int j=0;j<historial[i].size()-1;j++){
                    cout<<historial[i][j]<<"->";
                }
                cout<<historial[i][historial[i].size()-1]<<endl;
            }
            cout<<"Desea Eliminar Historial\n1.-Si\n2.-No\nElige una opcion: ";
            int opcionHistorial;
            cin>>opcionHistorial;
            if(opcionHistorial==1)
                historial.clear();
        }
        cout<<"Seleccione una opcion: ";
    }
}
