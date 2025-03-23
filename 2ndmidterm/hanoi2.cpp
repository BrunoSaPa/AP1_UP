#include <iostream>
using namespace std;
#define altura 5
//constants for visualization
#define ALTURA 5      //number of disks
#define ANCHO_TORRE 11 //width of each tower representation



int torres[altura];
int pisos[altura];
int alturas[3];

void mover_piedra(int,int,int);
void dibujar_piso(int);
void mover_piramide(int,int,int,int);

int main(){
    torres[4]=0;
    torres[3]=0;
    torres[2]=0;
    torres[1]=0;
    torres[0]=0;

    pisos[4]=0;
    pisos[3]=1;
    pisos[2]=2;
    pisos[1]=3;
    pisos[0]=4;

    alturas[0]=5;
    alturas[1]=0;
    alturas[2]=0;


    /*while(true){
	    for(int i=altura-1; i>=0; i--)
		    dibujar_piso(i);
    	    cout<<"------------------------------------------------"<<endl;
	    int piedra, destino;
	    cout<<"Qué piedra mover? (-1 para terminar)";
	    if (piedra==-1) break;
            cin>>piedra;
            cout<<"A qué torre moverla? ";
            cin>>destino;	
	    mover_piedra(piedra, torres[piedra], destino);    
    }*/

    mover_piramide(4,0,2,1);
}

void mover_piedra(int i, int inicio, int fin){
	torres[i]=fin;
	alturas[inicio]--;
	pisos[i]= alturas[fin];
	alturas[fin]++;

}



void dibujar_piso(int p){
	for (int j=0; j<3;j++){	
	  cout<<"\t";
	  bool dibujado=false;
	  for (int i=0; i<altura; i++)
		if (pisos[i]==p && torres[i]==j){
			cout<<i;
			dibujado=true;
		}
	  if (!dibujado)
		cout<<"-1";
	}
	cout<<endl;

}


void mover_piramide(int n, int from, int to, int aux)
{
    //base case
    if (n == 0) {
	    for(int i=altura-1; i>=0; i--)
		    dibujar_piso(i);
        cout<<"------------------------------------------------"<<endl;
        mover_piedra(n, from,to);
        return;
    }
    
    mover_piramide(n - 1, from, aux, to);

    for(int i=altura-1; i>=0; i--)
    dibujar_piso(i);
    cout<<"------------------------------------------------"<<endl;
    mover_piedra(n, from,to);


    mover_piramide(n - 1, aux, to ,from);
}