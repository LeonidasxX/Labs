import java.util.*;

class TableThread extends Thread{
	int n;
	public TableThread(int n){
		this.n = n;
		start();
	}
	synchronized public void run(){
		System.out.println(getName());
		for (int i = 1; i < 11; i++) {
			System.out.println(getName() + " " + n + " * " + i + " = " + (n*i));
		}
	}
}

class Tables{
	public static void main(String[] args) {
		TableThread m1 = new TableThread(5);
		TableThread m2 = new TableThread(7);
	}
}