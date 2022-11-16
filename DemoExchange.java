import java.util.*;

class Exchange<T>
{
	T [] ob;
	Exchange(T [] o){
		ob = o;
	}

	void exchange(int m, int n){
		T temp;
		temp = ob[m];
		ob[m]= ob[n];
		ob[n]= temp;
		System.out.println("Swapped...");
	}

	void display(){
		System.out.println("Current Array is: ");
		for (int i=0; i<5; i++) {
			System.out.print(ob[i] + " ");
		}
	}
}

class DemoExchange{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Exchange<Integer> iOb;
		Exchange<Character> jOb;
		Integer [] a = {1,2,3,4,5};
		iOb = new Exchange<Integer>(a);
		iOb.display();
		System.out.println();
		Character [] b = {'a', 'b', 'c', 'd', 'e'};
		jOb = new Exchange<Character>(b);
		jOb.display();
		System.out.println();
		System.out.println("Enter the index to exchange at: ");
		int m = sc.nextInt();
		int n = sc.nextInt();

		iOb.exchange(m, n);
		jOb.exchange(m, n);
		
		iOb.display();
		System.out.println();
		jOb.display();
	}
}