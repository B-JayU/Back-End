package chapter5;

public class Student { // 클래스는 대부분 대문자로 시작
	
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
		System.out.println("학번 : " + studentID);
		System.out.println("이름 : " + studentName);
		System.out.println("학점 : " + grade);
		System.out.println("주소 : " + address);
	}
	
	public String getStudentName() {
		return studentName;
	}
	
	public void setStudentName(String name) {
		studentName = name;
	}
	
	public static void main(String[] args) {
		
		Student studentLee = new Student();
		studentLee.studentName = "이순신";
		studentLee.studentID = 100;
		studentLee.address = "서울시 영등포구 여의도동";
		
		Student studentKim = new Student();
		studentKim.studentName = "김유신";
		studentKim.studentID = 101;
		studentKim.address = "미국 산호세";
		
		studentKim.showStudentInfo();
		studentLee.showStudentInfo();
	}
	
 }
