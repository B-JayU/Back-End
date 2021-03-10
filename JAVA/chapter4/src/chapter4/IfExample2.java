package chapter4;

public class IfExample2 {

	public static void main(String[] args) {
		
		int age = 9;
		int charge = 0;
		
		if (age < 8) {
			charge = 1000;
			System.out.println("미 취학 아동입니다.");
		}
		else if (age < 14) {
			charge = 2000;
			System.out.println("초등학생 입니다.");
		}else if (age < 20) {
			charge = 2500;
			System.out.println("중,고등 학생입니다.");
		}else {
			charge = 3000;
			System.out.println("일반 성인입니다.");
		}
		
		System.out.println("입장료는 " + charge + "원 입니다.");
	}
}
