#include <iostream>
#include <string>

using namespace std;

bool juego();
int main(){
	string jugador1,jugador2;
	cout<<"Ingrese el nombre del jugador de piezas blancas"<<endl;
	cin>>jugador1;
	cout<<"Ingrese el nombre del jugador de piezas negras"<<endl;
	cin>>jugador2;
	juego();
	return 0;

}