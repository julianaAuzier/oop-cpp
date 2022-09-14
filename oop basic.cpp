#include <iostream>
#include <locale>

using namespace std;

class Pessoa{	
	private:
		int id;
	
	public:
	   string nome, cidade, estado;
	   int idade;
	   
	   Pessoa(string n, int i, string c, string e){
		   nome = n;
		   idade = i;
		   cidade = c;
		   estado = e;
	   }
		
	// destrutor
		~Pessoa(){
		}
};

class Cargo{
	public:
		string nomeCargo;
		float salario;

		Cargo(const string nomeC, float salar){
			nomeCargo = nomeC;
			salario = salar;
		}
		
		~Cargo(){
		}
};

// herança simples
class Funcionario: public Pessoa{
	
	public:
	    float comissao, s_liquido;
	    string nomeCargo;
		
		Funcionario(const string n, int i, string c, string e, float comiss): Pessoa( n, i, c, e){
			comissao = comiss;
		}
	
		~Funcionario(){
		}
		
		//passando um objeto como parametro por referencia para outro objeto
		void Carg(Cargo &cargo){
			nomeCargo = cargo.nomeCargo;
			s_liquido = cargo.salario;
			
			if (comissao > 0){
				s_liquido = s_liquido + (comissao * s_liquido);
				
			}
		}
		
};

class Cliente: public Pessoa{
	public:
	   bool comprando = false;
	   float valorCompra;
	   
	public:
		Cliente(string n, int i, string c, string e, bool comprando = false): Pessoa( n, i, c, e){}
		
		~Cliente(){
		}
		
		void comprar(){
		if (comprando == true){
			cout << nome << " já está comprando." << endl;
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
			cout << nome << " não está comprando." << endl;
		}
	}
};
	
// herança multinível
class ClienteVip: public Cliente{ // que herda de Pessoa
	
	public:
		float desconto; // todo cliente vip terá 15% de desconto
		// ou
		// float desconto = 0.15;
	
	public:
		ClienteVip(string n, int i, string c, string e, bool comprando = false,  float d = 0.15): Cliente( n, i, c, e){
			desconto = d;
		}
		
		~ClienteVip(){
		}
		
	public:
		float valorFinal(){
		float novoValorCompra = valorCompra - (desconto * valorCompra);
		return novoValorCompra;
	}
};

int main() {

  // acentuação
  setlocale(LC_ALL, "portuguese");

  // objetos
  Cliente c1("Juliana", 25,"Belém", "Pará");
  ClienteVip c2("Julia", 30,"Santarém", "Pará");
  
  /********************TESTES**********************/
  cout <<"\nTestes com Clientes\n";
  cout <<"------------------------------\n";

  // já está comprando
  c1.comprar();
  c1.comprar();
  c1.EncerraCompra();
  c1.valorCompra = 15.00;
  cout <<"\n";
  
  // não está comprando
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
  
  Funcionario f1("Maria", 41,"Belém", "Pará", 0);
  Funcionario f2("Joao", 36,"Belém", "Pará", 0.15);
  
  f1.Carg(cg1);
  f2.Carg(cg2);
  
  cout << f1.nome << " recebe " << f1.comissao*100 << "% de comissão, portanto ganha " << f1.s_liquido << endl;
  cout <<f2.nome << " recebe " << f2.comissao*100 << "% de comissão, portanto ganha " << f2.s_liquido << endl;
  
  return 0;
}
