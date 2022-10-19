import java.util.*;
import com.course.structure.Building;
import com.course.structure.House;
import com.course.structure.School;

class demoBuilding{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Building b = new Building();
		House h = new House();
		School s = new School();

		System.out.println("Enter square foot of Building: ");
		int sqfoot = sc.nextInt();
		b.setfoot(sqfoot);

		System.out.println("Enter stories of Building: ");
		int stories = sc.nextInt();
		b.setstories(stories);

		System.out.println("Enter Number of bed rooms: ");
		int bedRooms = sc.nextInt();
		h.setbedRooms(bedRooms);

		System.out.println("Enter number of baths: ");
		int baths = sc.nextInt();
		h.setbaths(baths);

		System.out.println("Enter number of classrooms: ");
		int classRooms = sc.nextInt();
		s.setclassRooms(classRooms);

		sc.nextLine();
		System.out.println("Enter grade: ");
		String grade = sc.nextLine();
		s.setgrade(grade);

		System.out.println("Square Foot: " + b.getfoot());
		System.out.println("Stories: " + b.getstories());
		System.out.println("Number of BedRooms: " + h.getbed());
		System.out.println("Number of baths: " + h.getbaths());
		System.out.println("Number of ClassRooms: " + s.getclassRooms());
		System.out.println("Grade: " + s.getgrade());
	}
	
}