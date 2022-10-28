#include "Circulo.h" //no .h foi declarada a classe e os seus elementos (go check!)

// Heran�a Simples

Circulo::Circulo( ): Ponto( ) //construtor da classe recebe 3 double (x,y,raio) como parametros sem necessidade de alguma verifica��o.
							 // Como c�rculo herda de ponto, o construtor de Ponto deve ser "lembrado" aqui
{
	this->raio = 0; //se n�o � dado nenhum par�metro, o raio � 0 e na classe Ponto, x e y tamb�m ser�o 0 (go check!)
}

Circulo::Circulo( double xout, double yout, double raio ):Ponto( xout, yout ) //outro construtor da classe, possibilita a verifica��o dos parametros
{
	if( raio >= 0.0 )
	// this->raio (atributo da classe) = raio (par�metro)
		this->raio = raio;
	else
		this->raio = 1.0; // aqui n�o � aceito raio negativo (at� porque n�o faz sentido)
}

Circulo::Circulo( const Circulo &c_out ): Ponto( static_cast< Ponto >( c_out ) ) //construtor de c�pia da classe, como herda de Ponto, o construtor de c�dia de ponto � "lembrado".
																				// Aqui � passado para o contrutor de copia de Ponto a "parte Ponto" do obj Circulo (ou seja,somente x e y)
{
	this->raio = c_out.raio; // o raio � pego separado porque a "parte Ponto" do par�metro foi mandada para o novo objPonto.
							// Aqui � add o raio neste objeto e assim ele tamb�m � Circulo
}

Circulo::~Circulo(){ //destrutor
}

const Circulo &Circulo::operator= (const Circulo &cirOut ) //sobreposi��o de = (atribui��o) pra passar os valores de um objeto Circulo pra outro
{
	*static_cast< Ponto * >( this ) = static_cast< Ponto >( cirOut ); // a "parte Ponto" do objeto � esquerda de = recebe a "parte Ponto" do objeto � direita de =
	
	this->raio = cirOut.raio; // o raio � atribu�do separadamente
	
	return *this; 
}



ostream &operator<<( ostream &out, const Circulo &c )
{
	out << 	"Centro: " << static_cast< Ponto >( c ) << '\t';
	out << "Raio: " << c.raio;
		
	return out;
}

