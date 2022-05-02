class Stack{
    int [] values; //funciona como um ponteiro
    int free;

    Stack(){

        values = new int[100];
        free = 0;
    }

    void push(int value){

        values[free] = value;
        free++;
    }

    int pop(){

        free--;
        return values[free];
    }

    boolean empty(){
        return free = 0;
    }

}