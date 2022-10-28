#include "Ponto.h" //no .h foi declarada a classe e os seus elementos (go check!)

Ponto::Ponto( ): x(0), y(0){ // construtor da classe recebe 2 double (go check .h!) como parametros sem necessidade de alguma verificação
	
}

Ponto::Ponto( double xout, double yout):x(xout), y(yout){ //outro construtor da classe, possibilita a verificação dos parametros
	
}

Ponto::Ponto( const Ponto &pout ){ //construtor de copia da classe que recebe um objeto da propria classe e pega os dados desse objeto ao inves de pegar dados novos
	this->x = pout.x;
	this->y = pout.y;
}

Ponto::~Ponto(){ //destrutor
}

const Ponto &Ponto::operator= ( const Ponto &pOut ){ //sobrecarga de = (atribuição) pra passar os valores de um objeto pra outro
	this->x = pOut.x;
	this->y = pOut.y;
	
	return *this; // retorna x e y com os valores recebidos de outro objeto Ponto
}

ostream &operator<<( ostream &out, const Ponto &p ){ //sobrecarga de << para exibir x e y de objPonto
	out << '(' << p.x << ',' << p.y << ')';
	
	return out; //O operador sobrecarregado retorna uma referência ao objeto ostream original, o que significa que é possível combinar as inserções
}

