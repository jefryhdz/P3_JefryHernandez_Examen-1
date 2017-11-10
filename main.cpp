#include <iostream>
#include <string>
#include "Pieza.h"
#include "Blanca.h"
#include "Negra.h"

using namespace std;

bool juego();
Pieza*** creaciontablero();
int main(){
	string jugador1,jugador2;
	cout<<"Ingrese el nombre del jugador de piezas blancas"<<endl;
	cin>>jugador1;
	cout<<"Ingrese el nombre del jugador de piezas negras"<<endl;
	cin>>jugador2;
	if (juego())
	{
		cout<<"El jugador ganador es el que llevaba las blancas"<<endl;
		cout<<"el nombre: "<<jugador1;
	}else{
		cout<<"El jugador ganador es el que llevaba las negras"<<endl;
		cout<<"el nombre: "<<jugador2;
	}
	return 0;

}bool juego(){
	Pieza*** tablero=creaciontablero();
	int white=8;
	int black=8;
	int cont=0;
	while(white>1&&black>1){
		white--;
	}
	return false;

}Pieza*** creaciontablero(){
	Pieza*** tablero=new Pieza**[8];
	for (int i = 0; i <8; ++i)
	{
		tablero[i]= new Pieza*[8];
	}

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (((i==0)||(i==2))&&((j==0)||(j==2)||(j==4)||(j==6)))
			{
				Pieza* p = new Blanca();
				tablero[i][j]= p;
			}else if ((i==2)&&((j==1)||(j==3)||(j==5)||(j==7)))
			{
				tablero[i][j]= new Blanca();
			}else if ((i==6)&&(j==0)||(j==2)||(j==4)||(j==6))
			{
				tablero[i][j]= new Negra();
			}else if ((i==7||i==5)&&((j==1)||(j==3)||(j==5)||(j==7)))
			{
				tablero[i][j]= new Negra();
			}else{
				tablero[i][j]= NULL;			
			}
		}
	}
	return tablero;
}