#ifndef CIRCULO_H
#define CIRCULO_H


#include "Ponto.h"

#include <iostream>
using std::ostream;

const double PI = 3.14;

class Circulo : public Ponto
{
	friend ostream &operator<<( ostream &, const Circulo & );
public:
	Circulo( );
	Circulo( double, double, double = 0.0 ); 
	Circulo( const Circulo & );
	~Circulo();
	
	const Circulo &operator= ( const Circulo & );
	
	double calcArea( ) { return PI * raio * raio; } 

private:
	double raio;
	//double area;

};

#endif // CIRCULO_H
