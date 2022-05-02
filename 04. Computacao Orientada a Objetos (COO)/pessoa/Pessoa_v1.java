class Pessoa{

	int id;
	String nome;
}

class TestePessoa{

	public static void main(String [] args){

		// Como não instanciar objetos de uma classe...

		Pessoa p1 = new Pessoa();
		Pessoa p2 = new Pessoa();

		p1.id = 1234;
		p1.nome = "Pedro";

		p2.id = 2345;
		p2.nome = "Maria";
		
		System.out.println("Pessoa: id = " + p1.id + ", nome = " + p1.nome);
		System.out.println("Pessoa: id = " + p2.id + ", nome = " + p2.nome);
	}
}
