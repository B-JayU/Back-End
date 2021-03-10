package staticEx;

public class Student {
	
	// 모든 instance 변수들이 공유하는 static 변수
	private static int serialNum = 10000;
	
	// instance 마다 각각의 값을 값는 참조변수
	int studentID;
	String studentName;
	
	public Student() {
		serialNum++;
		this.studentID = serialNum;
	}

	// static 
	public static int getSerialNum() {
		return serialNum;
	}

	
	
	
}
