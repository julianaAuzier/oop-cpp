#include<iostream>

using namespace std;

/* jogo de corrida:
   as corridas são variáveis, alguns caminhos passam por pontes frageis em cima de rios,
   e algumas vezes os caminhos passam por pontes frageis entre abismos longos e profundos.
*/

class Veiculo{
	public:
		int velocidadeMaximaAtingida;
		string cor;
		int aceleracaoPS;
		
		Veiculo(int vma, string c, int aps){
			velocidadeMaximaAtingida = vma;
			cor = c;
			aceleracaoPS = aps;
		}
};

class Carro: virtual public Veiculo{
	public:
		int tamanhoPneu;
		string acessorio;
		
		Carro(int tp, string acess, int vma, string c, int aps):Veiculo(vma, c, aps){
			tamanhoPneu = tp;
			acessorio = acess;
		}
};

class VeiculoAquatico:virtual public Veiculo{
	public:
		int tamanhoHelice;
		int profundidadeMaximaAtingida;
		
		VeiculoAquatico(int th, int pma, int vma, string c, int aps):Veiculo(vma, c, aps){
			tamanhoHelice = th;
			profundidadeMaximaAtingida = pma;
		}
};

class VeiculoAereo:virtual public Veiculo{
	public:
		int tamanhoHelice;
		int alturaMaximaAtingida;
		
		VeiculoAereo(int th, int ama, int vma, string c, int aps):Veiculo(vma, c, aps){
			tamanhoHelice = th;
			alturaMaximaAtingida = ama;
		}
};

class Anfibio: public Carro, public VeiculoAquatico{
	bool terra = true;
	bool agua = false;
	
		public:
			string resp_user;

		// variaveis referentes a Carro /**/ variaveis referentes a VeiculoAquatico /**/ variaveis referentes a Veiculo
		Anfibio(int tp, string acess, /**/ int th, int pma, /**/ int vma, string c, int aps):Veiculo( vma, c, aps),Carro(tp, acess, vma, c, aps), VeiculoAquatico(th, pma, vma, c, aps){
			
		}
		
		
		string naTerra(){
			if (terra == 0){
				resp_user = "Nao esta na terra.\n";
			}
			else{
				resp_user="Esta na terra.\n";
			}
			return resp_user;
		}
		
		string naAgua(){
			if (agua == 0){
				resp_user = "Nao esta na agua.\n";
			}
			else{
				resp_user="Esta na agua.\n";
			}
			return resp_user;
		}
		
		void setAguaTerra(bool a, bool t){
			if(a == t){
				cout<<"Decida entre agua ou terra.\n";
			}
			else{
				agua = a;
				terra = t;
			}
		}
};

class AeroAquatico: public VeiculoAereo, public VeiculoAquatico{
	public:
		AeroAquatico(int th, int pma, /**/ int ama,/**/ int vma, string c, int aps):VeiculoAquatico(th, pma, vma, c, aps),VeiculoAereo(th, ama, vma, c, aps),Veiculo(vma, c, aps){};
};


//------------------------MAIN--------------------------

int main(int argc, char **argv){
	
	Carro car(30, "lanca",120 ,"preto",3);
	cout<<"INFORMACOES SOBRE O CARRO 'CAR'\n";
	cout<< "Velocidade maxima atingida: "<< car.velocidadeMaximaAtingida<< endl;
	cout<< "Cor: " << car.cor << endl;
	cout<< "Aceleracao por segundo: "<< car.aceleracaoPS<<endl;
	cout<< "Acessorio: "<< car.acessorio<<endl;
	cout<< "Tamanho do pneu: "<< car.tamanhoPneu<<endl;
	
	cout<<"-------------------------------------"<<endl;
	
	VeiculoAquatico aqua(20, 50, 80, "azul",2);
	cout<<"\nINFORMACOES SOBRE O VEICULO AQUATICO 'AQUA'\n";
	cout<<"Aceleracao por segundo: "<< aqua.aceleracaoPS << endl;
	cout<<"Cor: "<< aqua.cor << endl;
	cout<<"Velocidade maxima atingida: "<< aqua.velocidadeMaximaAtingida << endl;
	cout<<"Tamanho da helice: "<< aqua.tamanhoHelice << endl;
	
	cout<<"-------------------------------------"<<endl;
	
	Anfibio anf(20,"lanca",60,50,25,"vermelho",2);
	cout<<"\nINFORMACOES SOBRE O ANFIBIO 'ANF'\n";
	cout<<"Aceleracao por segundo: "<< anf.aceleracaoPS << endl;
	cout<<"Estou na agua?\n"<< anf.naAgua() << endl;
	cout<<"Estou na terra?\n"<< anf.naTerra() << endl;
	cout<<"Velocidade maxima atingida: "<< anf.velocidadeMaximaAtingida << endl;
	cout<<"Tamanho da helice: "<< anf.tamanhoHelice << endl;
	
	return 0;
}
