class Pessoa{

    //informacoes em private para nao dar acesso de fora
    private int id;
    private String nome;

    Pessoa(int id, String nome){ //constructor que recebe info
        System.out.println("Construtor1");

        this.id = id;
        this.nome = nome;

    }

    Pessoa(){ //cosntructor padrao no caso de nao receber nenhum elemento

        System.out.println("Construcotr 2");

        id = -1;
        nome = "undefined";
    }

    public void setId(int id){
        this.id = id;
    }

    public int getId(){
        return  this.id;
    }

    void imprimeInfo(){
        System.out.println("Pessoa: id = " + this.id + ", nome = " + this.nome);
    }
}

class TestePessoa{
    public static void main(String [] args){

        Pessoa p1 = new Pessoa(1234, "Pedro");
        Pessoa p2 = new Pessoa(2345, "Maria");
        Pessoa p3 = new Pessoa();

        p1.setId(100);

        p1.imprimeInfo();
        p2.imprimeInfo();
        p3.imprimeInfo();

    }
}