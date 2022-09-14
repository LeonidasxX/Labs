import java.util.*;

class Counter{
	static int count = 0;

	public Counter(){
		count += 1;
	}
	
	static void showCount(){
		System.out.println("Number of objects created: " + count);
	}
}

class DemoCounter{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Counter mc;
		System.out.println("1. add object 2. see the number of object created 3. exit");
		System.out.println("Enter choice: ");
		int c;
		c = sc.nextInt();

		while(c!=0){
			// System.out.println("1. add object 2. see the number of object created 3. exit");
			// int m = sc.nextInt();
			switch(c){
				case 1:
					mc = new Counter();
					break;
				case 2:
					Counter.showCount();
					break;
				default:
					System.out.println("Invalid Input");
			}
			System.out.println("Enter choice: ");
			c = sc.nextInt();	
		}
		
	}
}
