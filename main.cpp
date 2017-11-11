#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include "Pieza.h"
#include "Blanca.h"
#include "Negra.h"
#include <locale> 

using namespace std;

bool juego();
Pieza*** creaciontablero();
string Validarposiciones(string);
bool validar(string);
void print(Pieza***);
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
	int cont=1;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{	
			if (tablero[i][j]==NULL)
			{
				cout<<"[ ]";
			}else{
				cout<<"["<<tablero[i][j]->toString()<<"]";
			}
		}cout<<endl;
	}
	string posiciones;
	while(white>1&&black>1){

		if (cont%2==0)
		{
			cout<<"Juega el jugador de las negras"<<endl;
			cout<<"Ingrese las coordenadas a moverse"<<endl;
			cin>>posiciones;
			string position1,position2;
			position1= posiciones.substr(0,2);
			position2= posiciones.substr(3,4);
			string nueva =Validarposiciones(position1);
			string nueva2 =Validarposiciones(position2);
			char i=nueva[0];
			char j=nueva2[0];
			int inicio= i;
			inicio--;
			int final=j;
			char ii=nueva[1];
			char jj=nueva2[1];
			int inicioi= ii;
			inicioi--;
			int finalc=jj;
			if (validar(nueva)&&validar(nueva2))
			{				
				if (inicio>final&&inicioi>finalc)
				{
					if (tablero[inicioi][finalc]!= NULL&& tablero[inicioi][finalc]->toString()!="b")
					{
						if (tablero[jj++][finalc++]==NULL)
						{
							tablero[inicio][final]= NULL;
							tablero[inicioi][finalc]= NULL;
							tablero[inicioi++][finalc++]= new Blanca();

						}
					}
				}
			}print(tablero);


		}else{
			cout<<"Juega el jugador que  lleva blancas"<<endl;
			cout<<"Ingrese las coordenadas a moverse"<<endl;
			cin>>posiciones;
			string position1,position2;
			position1= posiciones.substr(0,2);
			position2= posiciones.substr(3,4);
			string nueva =Validarposiciones(position1);		
			string nueva2 =Validarposiciones(position2);			
			char i=nueva[0];
			char j=nueva2[0];
			int inicio= i;
			inicio--;
			int final=j;
			char ii=nueva[1];
			char jj=nueva2[1];
			int inicioi= ii;
			inicioi--;
			int finalc=jj;
			if (validar(nueva)&&validar(nueva2))
			{				
				if (inicio>final&&inicioi>finalc)
				{
					if (tablero[inicioi][finalc]!= NULL&& tablero[inicioi][finalc]->toString()!="w")
					{
						if (tablero[jj++][finalc++]==NULL)
						{
							tablero[inicio][final]= NULL;
							tablero[inicioi][finalc]= NULL;
							tablero[inicioi++][finalc++]= new Blanca();
							black--;

						}
					}
				}
				else if (inicioi<inicio&&finalc<final)
				{
					if (tablero[inicioi][finalc]!= NULL&& tablero[inicioi][finalc]->toString()!="w")
					{
						if (tablero[jj--][finalc--]==NULL)
						{
							tablero[inicio][final]= NULL;
							tablero[inicioi][finalc]= NULL;
							tablero[inicioi--][finalc--]= new Blanca();
							black--;

						}
					}
				}else if (inicioi>inicio&&finalc<final)
				{
					if (tablero[inicioi][finalc]!= NULL&& tablero[inicioi][finalc]->toString()!="w")
					{
						if (tablero[jj++][finalc--]==NULL)
						{
							tablero[inicio][final]= NULL;
							tablero[inicioi][finalc]= NULL;
							tablero[inicioi++][finalc--]= new Blanca();
							black--;

						}
					}
				}else if (inicioi<inicio&&finalc>final)
				{
					if (tablero[inicioi][finalc]!= NULL&& tablero[inicioi][finalc]->toString()!="w")
					{
						if (tablero[jj--][finalc++]==NULL)
						{
							tablero[inicio][final]= NULL;
							tablero[inicioi][finalc]= NULL;
							tablero[inicioi--][finalc++]= new Blanca();
							black--;

						}
					}
				}
			}
			print(tablero);
		}
		cont++;
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
			}else if ((i==1)&&((j==1)||(j==3)||(j==5)||(j==7)))
			{
				tablero[i][j]= new Blanca();
			}else if ((i==6)&&((j==0)||(j==2)||(j==4)||(j==6)))
			{
				tablero[i][j]= new Negra();
			}else if (((i==7)||(i==5))&&((j==1)||(j==3)||(j==5)||(j==7)))
			{
				tablero[i][j]= new Negra();
			}else{
				tablero[i][j]= NULL;			
			}
		}
	}
	return tablero;
}
string Validarposiciones(string posicion){
	string columna = posicion.substr(0,1);
	string fila= posicion.substr(1,2);	
	string columnanum="-1";//el num al final es para indicar que es el numero de la columna
	if(fila=="a"||fila=="A"){
		columnanum="0";
	}else if (columna=="b"||columna=="B")
	{
		columnanum="1";	
	}else if (columna=="c"||columna=="C")
	{
		columnanum="2";
	}else if (columna=="d"||columna=="D")
	{
		columnanum="3";
	}else if (columna=="e"||columna=="E")
	{
		columnanum="4";
	}else if (columna=="f"||columna=="F")
	{
		columnanum="5";
	}else if (columna=="g"||columna=="G")
	{
		columnanum="6";
	}else if (columna=="h"||columna=="H")
	{
		columnanum="7";
	}
	string inicial;
	inicial = fila;
	inicial+=columnanum;
	cout<<inicial<<endl;
	return inicial;
}
bool validar(string posicion){
	for (int i = 0; i < posicion.size(); ++i)
	{
		string temporal="";
		temporal= posicion[i];
		int temp=atoi(temporal.c_str());
		if (temp>8||temp<0)
		{
			return false;
		}
	}
	return true;
}
void print(Pieza*** mat){
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (mat[i][j]==NULL)
			{
				cout<<"[ ]";
			}else{
				cout<<"["<<mat[i][j]->toString()<<"]";
			}
		}cout<<endl;
	}

}