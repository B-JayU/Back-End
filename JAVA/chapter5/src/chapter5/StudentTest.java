package chapter5;

public class StudentTest {

	public static void main(String[] args) {
		
		Student studentYu = new Student(2017111399, "������");
		studentYu.address = "��� ��õ�� �ϻ굿";
		
		Student studentLee = new Student(2017103485, "�̼���");
		studentLee.address = "����� �������� ���ǵ���";
		
		studentYu.showStudentInfo();
		studentLee.showStudentInfo();
		
		System.out.println(studentYu);
		System.out.println(studentLee);
		
	}
}
