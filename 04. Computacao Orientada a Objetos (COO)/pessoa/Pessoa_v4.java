class Pessoa{

	// Melhorando ainda mais: restringindo a visibilidade dos atributos...
	
	private int id;
	private String nome;

	// Construtor adequado para a classe Pessoa

	Pessoa(int id, String nome) {

		this.id = id;
		this.nome = nome;
	}

	// método que imprime as informações do objeto 

	void imprimeInfo(){

		System.out.println("Pessoa: id = " + this.id + ", nome = " + this.nome);
	} 

	// getter e setter para acessar / modificar o id (assumindo
	// que os "usuários" classe Pessoa precisam ser capazes de 
	// acessar / modificar o valor de tal atributo).

	public int getId(){

		return this.id;
	}

	public void setId(int id){

		this.id = id;
	}
}

class TestePessoa{

	public static void main(String [] args){

		// Instanciando os objetos do tipo pessoa através do construtor...

		Pessoa p1 = new Pessoa(1234, "Pedro");
		Pessoa p2 = new Pessoa(2345, "Maria");

		// E executando as chamadas de método responsáveis por imprimir as informações dos objetos criados...

		p1.imprimeInfo(); 
		p2.imprimeInfo();

		// atualizando os ids...

		p1.setId(9876);
		p2.setId(8765);

		// imprimindo novamente as informações referentes a cada objeto...

		p1.imprimeInfo(); 
		p2.imprimeInfo();
	}
}
