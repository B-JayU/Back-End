package Cooperation;

public class Student {
	String studentName;
	int grade;
	int money;
	
	public Student(String studentName, int grade, int money) {
		this.studentName = studentName;
		this.grade = grade;
		this.money = money;
	}
	
	public void takeBus(Bus bus) { // � ������ Ÿ��? => ������ ���� ������ �ʿ��ϴ�.
		bus.take(1000); // ���� ž���� ���� ���� �����Ѵ�. 
		this.money -= 1000;			
	}
	
	public void takeSubway(Subway subway) { // � ������ Ÿ��? => ������ ���� ������ �ʿ��ϴ�.
		subway.take(1500); // ���� ž���� ���� ���� �����Ѵ�. 
		this.money -= 1500;		
		
	}
	
	public void showInfo() {
		System.out.println(studentName + "���� �ܾ��� " + money + "�Դϴ�.");
	}
	
	
	
	
}
