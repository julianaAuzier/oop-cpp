#include "Circulo.h" //no .h foi declarada a classe e os seus elementos (go check!)

// Herança Simples

Circulo::Circulo( ): Ponto( ) //construtor da classe recebe 3 double (x,y,raio) como parametros sem necessidade de alguma verificação.
							 // Como círculo herda de ponto, o construtor de Ponto deve ser "lembrado" aqui
{
	this->raio = 0; //se não é dado nenhum parâmetro, o raio é 0 e na classe Ponto, x e y também serão 0 (go check!)
}

Circulo::Circulo( double xout, double yout, double raio ):Ponto( xout, yout ) //outro construtor da classe, possibilita a verificação dos parametros
{
	if( raio >= 0.0 )
	// this->raio (atributo da classe) = raio (parâmetro)
		this->raio = raio;
	else
		this->raio = 1.0; // aqui não é aceito raio negativo (até porque não faz sentido)
}

Circulo::Circulo( const Circulo &c_out ): Ponto( static_cast< Ponto >( c_out ) ) //construtor de cópia da classe, como herda de Ponto, o construtor de códia de ponto é "lembrado".
																				// Aqui é passado para o contrutor de copia de Ponto a "parte Ponto" do obj Circulo (ou seja,somente x e y)
{
	this->raio = c_out.raio; // o raio é pego separado porque a "parte Ponto" do parâmetro foi mandada para o novo objPonto.
							// Aqui é add o raio neste objeto e assim ele também é Circulo
}

Circulo::~Circulo(){ //destrutor
}

const Circulo &Circulo::operator= (const Circulo &cirOut ) //sobreposição de = (atribuição) pra passar os valores de um objeto Circulo pra outro
{
	*static_cast< Ponto * >( this ) = static_cast< Ponto >( cirOut ); // a "parte Ponto" do objeto à esquerda de = recebe a "parte Ponto" do objeto à direita de =
	
	this->raio = cirOut.raio; // o raio é atribuído separadamente
	
	return *this; 
}



ostream &operator<<( ostream &out, const Circulo &c )
{
	out << 	"Centro: " << static_cast< Ponto >( c ) << '\t';
	out << "Raio: " << c.raio;
		
	return out;
}

