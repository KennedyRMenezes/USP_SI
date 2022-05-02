class Pessoa{

	int id;
	String nome;

	// Construtor adequado para a classe Pessoa

	Pessoa(int id, String nome) {

		this.id = id;
		this.nome = nome;
	}
}

class TestePessoa{

	public static void main(String [] args){

		// Instanciando os objetos do tipo pessoa através do construtor...

		Pessoa p1 = new Pessoa(1234, "Pedro");
		Pessoa p2 = new Pessoa(2345, "Maria");

		// Mas isso aqui ainda não está legal...
		
		System.out.println("Pessoa: id = " + p1.id + ", nome = " + p1.nome);
		System.out.println("Pessoa: id = " + p2.id + ", nome = " + p2.nome);
	}
}
