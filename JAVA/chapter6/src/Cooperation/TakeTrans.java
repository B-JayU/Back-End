package Cooperation;

public class TakeTrans {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Student james = new Student("James",3, 5000);
		Student thomas = new Student("Thomas", 5, 3000);
		
		Bus bus100 = new Bus(100);
		Subway sub001 = new Subway(001);
		
		james.takeBus(bus100);
		james.showInfo();
		bus100.showInfo();
		
		thomas.takeSubway(sub001);
		thomas.showInfo();
		sub001.showInfo();
		
		
	}

}
