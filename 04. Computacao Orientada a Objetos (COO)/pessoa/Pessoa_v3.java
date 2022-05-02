class Pessoa{

	int id;
	String nome;

	// Construtor adequado para a classe Pessoa

	Pessoa(int id, String nome) {

		this.id = id;
		this.nome = nome;
	}

	// método que imprime as informações do objeto 

	void imprimeInfo(){

		System.out.println("Pessoa: id = " + this.id + ", nome = " + this.nome);
	} 
}

class TestePessoa{

	public static void main(String [] args){

		// Instanciando os objetos do tipo pessoa através do construtor...

		Pessoa p1 = new Pessoa(1234, "Pedro");
		Pessoa p2 = new Pessoa(2345, "Maria");

		// E executando as chamadas do método responsável por imprimir as informações dos objetos criados...

		p1.imprimeInfo(); 
		p2.imprimeInfo();
	}
}
