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
		System.out.println("지하철 no." + lineNum + "번의 승객은 " + Passengers + "명이고 수입은 " + money + "입니다.");
	}
	
	
}
