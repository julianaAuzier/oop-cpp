#include <iostream>
#include <locale>

using namespace std;

class Pessoa{
	// atributos
	
	private: // default
		int id;
	
	public:
	   string nome;
	   int idade;
	   string cidade;
	   string estado;
	
	// construtor
	public:
		Pessoa(string n, int i, string c, string e){
			nome = n;
			idade = i;
			cidade = c;
			estado = e;
		}
};

// herança simples
class Cliente: public Pessoa{
	public:
	   bool comprando = false;
	   float valorCompra;
	   
	   
	public:
		Cliente(string n, int i, string c, string e, bool comprando = false): Pessoa( n, i, c, e){}
	
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
class ClienteVip: public Cliente{
	
	public:
		float desconto; // todo cliente vip terá 15% de desconto
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
		string NomeCargo;
		
	private:
		float salario;
	
	public:
	Cargo(string nomeC){
		NomeCargo = nomeC;
	}
	
	public:
		void setSalario(float s){
			salario = s;
		}
	
	public:
		float getSalario(){
			return salario;
		}
};

// herança múltipla
class Funcionario: public Pessoa, public Cargo {
	
	public:
	    float comissao;
	    float s_liquido = getSalario();
	    
	public:
		Funcionario(string n, int i, string c, string e, string nomeC, float comiss): Pessoa( n, i, c, e), Cargo(nomeC){
			comissao = comiss;
		}

	public:
		float salario_liquido(){
			if (comissao > 0){
				s_liquido = getSalario() + (comissao * getSalario());
				return s_liquido;
			}
			else{
				return getSalario();
			}
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
  
  Cargo cg1("Gerente");
  Cargo cg2("Vendedor");
  
  cg1.setSalario(1800.00);
  cg2.setSalario(1500);
  
  Funcionario f1("Maria", 41,"Belém", "Pará",cg1.NomeCargo, 0);
  Funcionario f2("Joao", 36,"Belém", "Pará",cg1.NomeCargo, 0.2);
  cout<< f1.getSalario() <<endl;
  cout<< f1.salario_liquido() <<endl;
  cout<< f1.s_liquido <<endl;
  cout<< cg1.getSalario() <<endl;
  cout<< f1.NomeCargo <<endl;
  cout<< f2.comissao <<endl;
  /*
  cout <<f1.nome << " recebe " << f1.comissao*100 << "% de comissão, portanto ganha " << f1.getSalario() << endl;
  cout <<f2.nome << " recebe " << f2.comissao*100 << "% de comissão, portanto ganha " << f2.salario_liquido() << endl;
  */
  return 0;
}
