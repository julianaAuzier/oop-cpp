#include "Cilindro.h"

Cilindro::Cilindro( )
: Circulo(  )
{
	this->altura = 0;
}


Cilindro::Cilindro( double x, double y, double raio, double altura )
:Circulo( x, y, raio )
{
	if( altura > 0 )
		this->altura = altura;
	else
		this->altura = 1;
}

Cilindro::Cilindro( const Cilindro & circOut )
:  Circulo( static_cast< Circulo >( circOut ) )
{
	this->altura = circOut.altura;
}



Cilindro::~Cilindro()
{
}

const Cilindro &Cilindro::operator=( const Cilindro &cilOut )
{
	*static_cast< Circulo * >( this ) = static_cast< Circulo >( cilOut );
	
	this->altura = cilOut.altura;	
	
	return *this;
}

ostream &operator<<( ostream &out, const Cilindro &cil )
{
	out << 	"Base: " << static_cast< Circulo >( cil ) << '\n';
	out << "A altura eh " << cil.altura;
		
	return out;
}
