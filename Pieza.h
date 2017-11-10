#ifndef PIEZA_H
#define PIEZA_H
#include <string>
using namespace std;

class Pieza
{	private:
		bool sargento;

	public:
		Pieza();
		void setSargento(bool);
		virtual string toString();
		~Pieza();
	
};
#endif