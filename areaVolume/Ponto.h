#ifndef PONTO_H
#define PONTO_H

#include <iostream>
using std::ostream;

class Ponto
{
 /* Podemos ensinar o c++ como queremos que ele
	imprima um objeto de uma classe que criamos
	sobrecarregando o operador <<
	---------------------------------------------
	a função friend não faz parte da classe,
	mas é uma "amiga" da classe e por isso quebra
	o encapsulamento podendo acessar elementos
	privados da classe.
	---------------------------------------------
	"ostream" é uma das classes definidas em "iostream.h"
	---------------------------------------------
	objetivo: Sobrecarregue o operador << pra quando o
	cpp ver o objeto da classe ostream << e depois um
	objeto da classe Ponto, ele vai se comportar de
	determinada forma
*/
	friend ostream &operator<<( ostream &, const Ponto & );
	/* 	vamos acessar algumas coisas da classe 
		independente se são publicas, privadas
		ou protegidas pra fazer esse método.
		Quer dizer que:
		quando vc se deparar com o operador <<
		da classe ostream, vc vai ver se depois
		tem um objeto da classe Ponto e vai
		executar de tal forma (que está no .cpp)
		recebendo como parametro a referencia
		do ostream e a referencia do objeto da
		classe Ponto.
	*/
	
public:
	Ponto( );				  // construtor da classe
	Ponto( double, double ); // construtor da classe
	Ponto( const Ponto & ); // construtor de copia da classe, sobrecarregando o construtor da classe
	~Ponto();
	
	const Ponto &operator= ( const Ponto & );// sobrecarga de = (atribuição). Quando ele ver algo = objPonto ele vai receber os valores de x e y
	
	
private:

	double x;
	double y;

};

#endif // PONTO_H
