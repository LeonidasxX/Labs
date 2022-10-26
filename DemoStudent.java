import java.util.*;
// import java.util.GregorianCalendar;

class SeatsFilledException extends Exception{
    public SeatsFilledException(){
		toString();
	}
    public String toString(){
        return "Seats Full...";
    }
}

class Student{
	int reg;
	String name;
	int year;
	int month;
	int day;
	GregorianCalendar doj = new GregorianCalendar(year,month,day);
	short sem;
	float gpa;
	float cgpa;

	public Student(){
		reg = 0;
		name = null;
		year = 0;
		month = 0;
		day = 0;
		sem = 0;
		gpa = 0;
		cgpa = 0;
	}

	public Student(String r, String n, int y, int m, int d, short s, float g, float c){
		reg = Integer.parseInt(r);
		name = n;
		year = y;
		month = m;
		day = d;
		sem = s;
		gpa = g;
		cgpa = c;
	}

	void display(){
		System.out.println("--------------------------------------------------");
		System.out.println("Name: "+name);
		System.out.println("Registration Number: "+reg);
		System.out.println("Date of Joining: "+ doj.getTime());
		System.out.println("Semester: "+sem);
		System.out.println("GPA: "+gpa);
		System.out.println("CGPA: "+cgpa);
	}
}

class DemoStudent{
	public static void main(String[] args) throws SeatsFilledException {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of students: ");
		int n = sc.nextInt();

		Student a = new Student();
		a.display();

		Student s[] = new Student[n];
		for (int i=0; i<n; i++) {
            if(i>2){
                throw(new SeatsFilledException());
            }
			System.out.println("-------------------------------------------------");
			System.out.println("Enter the records for student "+(i+1));
			sc.nextLine();
			System.out.println("Enter Name: ");
			String name = sc.nextLine();
			System.out.println("Enter the year of joining: ");
			int year = sc.nextInt();
			System.out.println("Enter the month of joining: ");
			int month = sc.nextInt();
			System.out.println("Enter the day of joining: ");
			int day = sc.nextInt();
			System.out.println("Enter Semester: ");
			short sem = sc.nextShort();
			System.out.println("Enter GPA: ");
			float gpa = sc.nextFloat();
			System.out.println("Enter CGPA: ");
			float cgpa = sc.nextFloat();
			String reg = (year-2000)+""+(i+1);
			s[i] = new Student(reg, name, year, month, day, sem, gpa, cgpa);
		}

		System.out.println("Entered records are:");
		for (int i=0; i<n; i++) {
			System.out.println("Records for student "+(i+1));
			s[i].display();
		}

		Student temp = new Student();
		System.out.println("Enter choice for sorting: 1. Semester 2. CGPA 3. Name");
		int ch = sc.nextInt();
		while(ch!=0){
		switch(ch){
			case 1:
				System.out.println("Sorted according to Semester:");
				for (int i=0; i<n; i++) {
					for (int j=0; j<n-1; j++) {
						if (s[j].sem < s[j+1].sem) {
							temp = s[j];
							s[j] = s[j+1];
							s[j+1] = temp;
						}
					}
				}
				for (int i=0; i<n; i++) {
					s[i].display();
				}
				break;

			case 2:
				System.out.println("Sorted according to CGPA:");
				for (int i=0; i<n; i++) {
					for (int j=0; j<n-1; j++) {
						if (s[j].cgpa < s[j+1].cgpa) {
							temp = s[j];
							s[j] = s[j+1];
							s[j+1] = temp;
						}
					}
				}
				for (int i=0; i<n; i++) {
					s[i].display();
				}
				break;

			case 3:
				System.out.println("Sorted according to GPA:");
				for (int i=0; i<n; i++) {
					for (int j=0; j<n-1; j++) {
						if (s[j].name.compareTo(s[j+1].name)<0) {
							temp = s[j];
							s[j] = s[j+1];
							s[j+1] = temp;
						}
					}
				}
				for (int i=0; i<n; i++) {
					s[i].display();
				}
				break;
		}
		System.out.println("Enter next choice: ");
		ch = sc.nextInt();
	}

		System.out.println("Enter choice for listing according to: 1. character 2. sub-string 3. change initials");
		ch = sc.nextInt();

		while(ch!=0){
		switch(ch){
			case 1:
				System.out.println("Listing according to character...");
				System.out.print("Enter the character: ");
				String chr = sc.next();
				for (int i=0; i<n; i++) {
					if (s[i].name.startsWith(chr)) {
						System.out.println((i+1)+". "+s[i].name);
					}
				}
				System.out.println("---------------------------");
				break;

			case 2:
				System.out.println("Listing according to sub-string...");
				System.out.print("Enter the sub-string: ");
				chr = sc.next();
				for (int i=0; i<n; i++) {
					if (s[i].name.indexOf(chr) != -1) {
						System.out.println((i+1)+". "+s[i].name);
					}
				}
				System.out.println("---------------------------");
				break;

			case 3:
				System.out.println("Listing according to changed initials...");
				for (int i=0; i<n; i++) {
					if (s[i].name.indexOf(" ") != s[i].name.lastIndexOf(" ")) {
						System.out.print((i+1)+". ");
						int x = s[i].name.indexOf(" ");
						System.out.print(s[i].name.charAt(0)+".");
						System.out.print(s[i].name.charAt(x+1)+".");
						x = s[i].name.lastIndexOf(" ");
						System.out.print(s[i].name.substring(x+1));	
					}
				}
				System.out.println("---------------------------");
				break;
		}
		System.out.println("Enter next choice: ");
		ch = sc.nextInt();
	}
	}
}