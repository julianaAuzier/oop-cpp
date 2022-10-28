#include "Cilindro.h" //no .h foi declarada a classe e os seus elementos (go check!)

// Herança Multinível

Cilindro::Cilindro( ): Circulo(  ) // construtor da classe, como herda de Circulo, então o construtor de Circulo deve ser "lembrado" aqui
{
	this->altura = 0;
}


Cilindro::Cilindro( double x, double y, double raio, double altura ) // construtor quando recebe parâmetros que podem passar por verificação
:Circulo( x, y, raio ) //os parametros x, y e raio
{
	if( altura > 0 ) // a altura deverá ser maior que 0 pra que seja um cilindro, caso contrário será só mais um círculo!
		this->altura = altura; // a (this) altura (declarada no .h // go check! //) recebe o valor da altura (parâmetro) de forma
		//						separada porque os outros parâmetros são passados para os atributos da classe Cilindro, serão tratados lá
	else
		this->altura = 1; // se a altura dada for <1, o valor será 1
}

Cilindro::Cilindro( const Cilindro & circOut ):Circulo( static_cast< Circulo >( circOut ) ) // construtor de cópia: recebe um obj da propria classe e
//																							   passa a "parte Circulo" desse obj para a classe Circulo
{
	this->altura = circOut.altura; // pega a altura (atributo a+ que tem em Cilindro) separadamente
}



Cilindro::~Cilindro() //destrutor
{
}

const Cilindro &Cilindro::operator=( const Cilindro &cilOut ) // sobreposição do operador = (atribuição) para um obj da classe pegue
//																 os mesmos valores de outro obj da propria classe
{
	*static_cast< Circulo * >( this ) = static_cast< Circulo >( cilOut ); // a "parte Circulo" do objeto à esquerda de = recebe a "parte Circulo" do objeto à direita de =
	
	this->altura = cilOut.altura;
	
	return *this;
}

ostream &operator<<( ostream &out, const Cilindro &cil ) //sobreposicao de <<. Quando o c++ ver a estrutura: objeto da classe ostream (cout) << objeto de Cilindro..
{
	out << 	"Base: " << static_cast< Circulo >( cil ) << '\n'; // ..ele vai mostrar a base do cilindro, que é um circulo (a parte Circulo do objeto)
	out << "A altura eh " << cil.altura;
		
	return out;
}
