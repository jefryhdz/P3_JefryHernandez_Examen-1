#ifndef NEGRA_H
#define NEGRA_H
#include "Pieza.h"
#include <string>

using namespace std;

class Negra: public Pieza
{
public:
	Negra();
	string toString();
	~Negra();
	
};

#endif