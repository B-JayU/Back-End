package staticEx;

public class StudentTest {

	public static void main(String[] args) {
		
		Student kim = new Student();
		System.out.println(kim.studentID);
	
		
		Student lee = new Student();
		System.out.println(lee.studentID);
		
		
		// static변수는 클래스이름을 이용하여 참조한다.
		System.out.println(Student.getSerialNum());
		System.out.println(Student.getSerialNum());
		
		
		
		
	}

}
