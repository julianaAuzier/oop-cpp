#ifndef CILINDRO_H
#define CILINDRO_H

#include "Circulo.h"

class Cilindro : public Circulo
{
	friend ostream &operator<<( ostream &, const Cilindro & );
public:
	Cilindro( );
	Cilindro( double, double, double, double );
	Cilindro( const Cilindro & );
	~Cilindro();

	const Cilindro &operator= ( const Cilindro & );
	
	double calcVolume( ) { return altura * Circulo::calcArea( ); }
	
	
private:
	double altura;

};

#endif // CILINDRO_H
