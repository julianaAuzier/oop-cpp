#include <iostream>
#include <locale>

using namespace std;

class Pessoa{	
	private:
		int id;
	
	public:
	   string nome;
	   int idade;
	   string cidade;
	   string estado;

	public:
		Pessoa(string n, int i, string c, string e){
			nome = n;
			idade = i;
			cidade = c;
			estado = e;
		}
		
	// destrutor
		~Pessoa(){
			cout << "Destruidor chamado." << endl;
		}
};

// heran�a simples
class Cliente: public Pessoa{
	public:
	   bool comprando = false;
	   float valorCompra;
	   
	   
	public:
		Cliente(string n, int i, string c, string e, bool comprando = false): Pessoa( n, i, c, e){}
	
		void comprar(){
		if (comprando == true){
			cout << nome << " j� est� comprando." << endl;
		}
		else{
			comprando = true;
			cout << nome << " vai comprar agora." << endl;
		}
	}
	
	void EncerraCompra(){
		if (comprando == true){
			comprando = false;
			cout << nome << " encerrou a compra." << endl;
		}
		else{
			cout << nome << " n�o est� comprando." << endl;
		}
	}
};
	
// heran�a multin�vel
class ClienteVip: public Cliente{
	
	public:
		float desconto; // todo cliente vip ter� 15% de desconto
		// ou
		// float desconto = 0.15;
	
	public:
		ClienteVip(string n, int i, string c, string e, bool comprando = false,  float d = 0.15): Cliente( n, i, c, e){
			desconto = d;
	 }
	
	public:
	float valorFinal(){
		float novoValorCompra = valorCompra - (desconto * valorCompra);
		return novoValorCompra;
	}
};

// mais uma classe...
class Cargo{
	public:
		string nomeCargo;
		float salario;

		Cargo(string nomeC, float salar){
			nomeCargo = nomeC;
			salario = salar;
		}
};

class Funcionario: public Pessoa{
	
	public:
	    float comissao;
	    float s_liquido;
	    string nomeCargo;
		
		Funcionario(string n, int i, string c, string e, float comiss): Pessoa( n, i, c, e){
			comissao = comiss;
		}
	
		void Carg(Cargo &cargo){
			nomeCargo = cargo.nomeCargo;
			s_liquido = cargo.salario;
			
			if (comissao > 0){
				s_liquido = s_liquido + (comissao * s_liquido);
				
			}
		}
		
};

int main() {

  // acentua��o
  setlocale(LC_ALL, "portuguese");

  // objetos
  Cliente c1("Juliana", 25,"Bel�m", "Par�");
  ClienteVip c2("Julia", 30,"Santar�m", "Par�");
  
  /********************TESTES**********************/
  cout <<"\nTestes com Clientes\n";
  cout <<"------------------------------\n";

  // j� est� comprando
  c1.comprar();
  c1.comprar();
  c1.EncerraCompra();
  c1.valorCompra = 15.00;
  cout <<"\n";
  
  // n�o est� comprando
  c2.EncerraCompra();
  c2.comprar();
  c2.EncerraCompra();
  c2.valorCompra = 25.00;
  cout <<"\n";
  
  // dados de clientes
  cout << c1.nome << " mora em " << c1.cidade << " no estado do " << c1.estado << endl;
  cout <<"\n";
  cout << c2.nome << " mora em " << c2.cidade << " no estado do " << c2.estado << endl;
  cout << c2.nome << " ganhou " << c2.desconto*100 << "% de desconto, a compra de "<< c2.valorCompra << " reais saiu por " << c2.valorFinal() << " reais." << endl;
  
  /**************************************************/
  cout <<"\n\n------------------------------";
  cout <<"\nTestes com Funcionarios\n";
  cout <<"------------------------------\n";
  
  Cargo cg1("Gerente",1800.00);
  Cargo cg2("Vendedor",1500);
  
  Funcionario f1("Maria", 41,"Bel�m", "Par�", 0);
  Funcionario f2("Joao", 36,"Bel�m", "Par�", 0.15);
  
  f1.Carg(cg1);
  f2.Carg(cg2);
  
  cout << f1.nome << " recebe " << f1.comissao*100 << "% de comiss�o, portanto ganha " << f1.s_liquido << endl;
  cout <<f2.nome << " recebe " << f2.comissao*100 << "% de comiss�o, portanto ganha " << f2.s_liquido << endl;
  
  return 0;
}
