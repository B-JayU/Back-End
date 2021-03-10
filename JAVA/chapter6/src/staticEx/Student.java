package staticEx;

public class Student {
	
	// ��� instance �������� �����ϴ� static ����
	private static int serialNum = 10000;
	
	// instance ���� ������ ���� ���� ��������
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
