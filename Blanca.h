#ifndef BLANCA_H
#define BLANCA_H
#include "Pieza.h"
#include<string>

using namespace std;
class Blanca: public Pieza
{
public:
	Blanca();
	string toString();
	~Blanca();
	
};

#endif