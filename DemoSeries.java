import java.util.*;

interface Series{
	int getNext(int n);
	int reset();
	int setStart();
}

class ByTwos implements Series{
	int start;
	ByTwos(){
		start = 0;
	}
	public int getNext(int n){
		return n+2;
	}
	public int setStart(){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the starting value:");
		start = sc.nextInt();
		return start;
	}
	public int reset(){
		System.out.println("Reseting Value...");
		return start;
	}
}

class DemoSeries{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Series s = new ByTwos();
		boolean check = true;
		int choice;
		int ele = 0;
		ele = s.setStart();
		System.out.println("ele: " + ele);
		while(check){
			System.out.println("1.setStart\n2.getNext\n3.reset\n4.Exit");
			choice = sc.nextInt();
			switch(choice){
			case 1:
				ele = s.setStart();
				break;
			case 2:
				ele = s.getNext(ele);
				System.out.println(ele);
				break;
			case 3:
				ele = s.reset();
				System.out.println(ele);
				break;
			case 4:
				System.out.println("Exiting...");
				check = false;
				break;
			default:
				System.out.println("Invalid Input");
				break;
			}
		}
	}
}