package Cooperation;

public class Subway {
	int lineNum;
	int Passengers=0;
	int money=0;
	
	public Subway() {}
	
	public Subway(int lineNum) {
		this.lineNum = lineNum;
	}
	
	public void take(int money) {
		this.Passengers += 1;
		this.money += money;
	}
	
	public void showInfo() {
		System.out.println("����ö no." + lineNum + "���� �°��� " + Passengers + "���̰� ������ " + money + "�Դϴ�.");
	}
	
	
}
