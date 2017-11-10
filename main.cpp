#include <iostream>
#include <string>

using namespace std;

bool juego();
Pieza*** creaciontablero();
int main(){
	string jugador1,jugador2;
	cout<<"Ingrese el nombre del jugador de piezas blancas"<<endl;
	cin>>jugador1;
	cout<<"Ingrese el nombre del jugador de piezas negras"<<endl;
	cin>>jugador2;
	juego();
	return 0;

}bool juego(){
	Pieza*** tablero=creaciontablero();


}Pieza*** creaciontablero(){
	Pieza*** tablero=new Pieza**[8];
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (((i==0)||(i==2))&&((j==0)||(j==2)||(j==4)||(j==6))
			{
				tablero[i][j]= new Blanca();
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