package staticEx;

public class StudentTest {

	public static void main(String[] args) {
		
		Student kim = new Student();
		System.out.println(kim.studentID);
	
		
		Student lee = new Student();
		System.out.println(lee.studentID);
		
		
		// static������ Ŭ�����̸��� �̿��Ͽ� �����Ѵ�.
		System.out.println(Student.getSerialNum());
		System.out.println(Student.getSerialNum());
		
		
		
		
	}

}
