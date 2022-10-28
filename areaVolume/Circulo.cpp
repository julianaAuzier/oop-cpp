#include "Circulo.h"

Circulo::Circulo( ): Ponto( )
{
	this->raio = 0;
}


Circulo::Circulo( double xout, double yout, double raio )
:Ponto( xout, yout )
{
	if( raio >= 0.0 )
		this->raio = raio;
	else
		this->raio = 1.0;
}

Circulo::Circulo( const Circulo &c_out ): Ponto( static_cast< Ponto >( c_out ) ) // passa para o contrutor de copia de Ponto a parte de Ponto do obj Circulo
{
	this->raio = c_out.raio;
}

Circulo::~Circulo(){
}

const Circulo &Circulo::operator= ( const Circulo &cirOut ) //sobreposição pra passar os valores de um objeto pra outro
{
	*static_cast< Ponto * >( this ) = static_cast< Ponto >( cirOut );	
	
	this->raio = cirOut.raio;	
	
	return *this;
}



ostream &operator<<( ostream &out, const Circulo &c )
{
	out << 	"Centro: " << static_cast< Ponto >( c ) << '\t';
	out << "Raio: " << c.raio;
		
	return out;
}

