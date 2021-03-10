package chapter5;

public class StudentTest {

	public static void main(String[] args) {
		
		Student studentYu = new Student(2017111399, "유병주");
		studentYu.address = "경북 영천시 완산동";
		
		Student studentLee = new Student(2017103485, "이순신");
		studentLee.address = "서울시 영등포구 여의도동";
		
		studentYu.showStudentInfo();
		studentLee.showStudentInfo();
		
		System.out.println(studentYu);
		System.out.println(studentLee);
		
	}
}
