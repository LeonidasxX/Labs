import java.util.*;

class Stack<T>{
	T ob[];
	int tos;

	Stack (T [] o) {
		tos = -1;
		ob = o;
	}
	
	boolean isEmpty () {
		return (tos == -1);
	}

	void push (T item) {
		if (tos == ob.length - 1) {
			System.out.println("\n\tSTACK OVERFLOW!");
			return;
		}
		ob[++tos] = item;
	}

	T pop () {
		if (tos == -1) {
			System.out.println("\n\tSTACK UNDERFLOW!");
			return null;
		}
		return ob[tos--];
	}

	
	
}

class Student{
	String name;
	int age;
	String isDead;

	Student(String name, int age, String isDead){
		this.name = name;
		this.age = age;
		this.isDead = isDead;
	}

	void display()
	{
		System.out.println("Name: " + name);
		System.out.println("Age: " + age);
		System.out.println("Is he Dead?: " + isDead);
	}
}

class Employee{
	String name;
	int eid;
	String wanna_die;

	Employee(String name, int eid, String wanna_die){
		this.name = name;
		this.eid = eid;
		this.wanna_die = wanna_die;
	}

	void display()
	{
		System.out.println("Name: " + name);
		System.out.println("Eid: " + eid);
		System.out.println("Does he wanna die?: " + wanna_die);
	}
}

class DemoStack{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Stack<Student> sOb;
		Stack<Employee> eOb;

		Student s1 = new Student("Gautam", 18, "Not_yet");
		Student s2 = new Student("Shouvik", 19, "Probably_soon");
		Student s3 = new Student("Shagun", 12, "IfNotSomeOneWill");
		Student [] s = new Student[3];
		sOb = new Stack<Student>(s);
		sOb.push(s1);
		s1.display();
		sOb.push(s2);
		s2.display();
		sOb.push(s3);
		s3.display();

		Employee e1 = new Employee("Ronan", 28, "MentionsAlot");
		Employee e2 = new Employee("Sidhharth", 29, "BandiMilGayi");
		Employee [] e = new Employee[3];
		eOb = new Stack<Employee>(e);
		eOb.push(e1);
		e1.display();
		eOb.push(e2);
		e2.display();

		System.out.println("Poping Student: ");

		Student sv = sOb.pop();
		sv.display();

		System.out.println("Poping Employee: ");

		Employee ev = eOb.pop();
		ev.display();


	}
}