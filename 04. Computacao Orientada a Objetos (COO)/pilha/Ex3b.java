import java.util.*;

// Tradução "literal" do código ex3.c para Java.
// Não usufrui plenamente dos recursos oferecidos
// por uma linguagem orientada a objetos. Classe
// Stack não possui um bom encapsulamento devido
// à decisão de manter a declaração do tipo Stack
// desvinculada das operações associadas à estrutura.

class Stack {

	int [] values;
	int free;
}

public class Ex3b {

	static void init(Stack stack){

		stack.values = new int[100];
		stack.free = 0;
	}

	static void push(Stack stack, int value){

		stack.values[stack.free] = value;
		stack.free++;
	}

	static int pop(Stack stack){

		stack.free--;
		return stack.values[stack.free];	
	}

	static boolean empty(Stack stack){

		return stack.free == 0;
	}

	public static void main(String [] args){
	
		int value;
		Stack stack = new Stack();
		Scanner scanner = new Scanner(System.in);
	  
		init(stack);
	  
		while( (value = scanner.nextInt()) > 0){
	    
			push(stack, value);	
	  	}
	  
		System.out.print("Conteudo em ordem reversa:");
	  
		while(!empty(stack)) {
    
			value = pop(stack);
	    		System.out.print(" " + value);
	  	}
	
		System.out.println();
	}
}
