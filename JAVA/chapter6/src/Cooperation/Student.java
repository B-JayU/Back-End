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
	
	public void takeBus(Bus bus) { // 어떤 버스를 타냐? => 버스에 대한 정보가 필요하다.
		bus.take(1000); // 버스 탑승을 위해 돈을 지불한다. 
		this.money -= 1000;			
	}
	
	public void takeSubway(Subway subway) { // 어떤 버스를 타냐? => 버스에 대한 정보가 필요하다.
		subway.take(1500); // 버스 탑승을 위해 돈을 지불한다. 
		this.money -= 1500;		
		
	}
	
	public void showInfo() {
		System.out.println(studentName + "님의 잔액은 " + money + "입니다.");
	}
	
	
	
	
}
