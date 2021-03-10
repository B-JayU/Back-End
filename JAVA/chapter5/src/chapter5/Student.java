package chapter5;

public class Student { // Ŭ������ ��κ� �빮�ڷ� ����
	
	int studentID;
	String studentName;
	int grade;
	String address;
	
	
	public Student () {
		// default constructor
	}
	
	public Student(int id, String name) {
		studentID = id;
		studentName = name;
	}
	
	public void showStudentInfo() {
		System.out.println("�й� : " + studentID);
		System.out.println("�̸� : " + studentName);
		System.out.println("���� : " + grade);
		System.out.println("�ּ� : " + address);
	}
	
	public String getStudentName() {
		return studentName;
	}
	
	public void setStudentName(String name) {
		studentName = name;
	}
	
	public static void main(String[] args) {
		
		Student studentLee = new Student();
		studentLee.studentName = "�̼���";
		studentLee.studentID = 100;
		studentLee.address = "����� �������� ���ǵ���";
		
		Student studentKim = new Student();
		studentKim.studentName = "������";
		studentKim.studentID = 101;
		studentKim.address = "�̱� ��ȣ��";
		
		studentKim.showStudentInfo();
		studentLee.showStudentInfo();
	}
	
 }
