package Cooperation;

public class Bus {
	int busNum;
	int Passengers=0;
	int money=0;
	
	public Bus() {}
	
	public Bus(int busNum) {
		this.busNum = busNum;
	}
	
	public void take(int money) {
		this.Passengers += 1;
		this.money += money;
	}
	
	public void showInfo() {
		System.out.println("���� no." + busNum + "���� �°��� " + Passengers + "���̰� ������ " + money + "�Դϴ�.");
	}
	
}
