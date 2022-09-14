import java.util.*;

class Stack{
    int arr[] = new int[100];
    int tos;

    void initialize(){
        this.tos = -1;
    }

    void push(int x){
        if(tos>=100){
            System.out.println("Stack Overflow");
            return;
        }
        this.tos++;
        this.arr[this.tos]=x;
    }
    void pop(){
        if(tos<0){
            System.out.println("Stack Underflow");
            return;
        }
        this.tos--;
    }

    void display(){
        if(tos>=0){
            System.out.println("Stack elements are: ");
            for(int i=0; i<= this.tos; i++){
                System.out.print(this.arr[i] + " ");
            }
            System.out.println();
        }
        else{
            System.out.println("Stack Empty: ");
        }
    }

}

class DemoStack{
    static void choice(){
        System.out.println("1. Push Element");
        System.out.println("2. Pop Element");
        System.out.println("3. Display Stack");
        System.out.println("4. Exit");
        System.out.println("Enter choice: ");
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack stack = new Stack();
        stack.initialize();
        int x, c;
        choice();
        c = sc.nextInt();
        while(c!=4){
            switch (c) {
                case 1:
                    System.out.print("Enter the element to be inserted: ");
                    x = sc.nextInt();
                    stack.push(x);
                    break;
                case 2:
                    stack.pop();
                    break;
                case 3:
                    stack.display();
                    break;
                case 4:
                    break;
                default:
                System.out.print("Invalid input: ");
                    break;
            }
            System.out.println();
            choice();
            c = sc.nextInt();
        }
    }
}
