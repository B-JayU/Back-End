package interfaceEx;

public interface Calc {

	// public static final 변수로 선언됨. 정적변수
	double PI = 3.14;
	int ERROR = -999999999;
	
	// interface 안에 default로 선언하면 public abstract method로 자동 debugging 됨.
	
	int add(int num1,int num2);
	int substract(int num1, int num2);
	int times(int num1, int num2);
	int divide(int num1, int num2);

	default void description() {
		System.out.println("정수 계산기를 구합니다.");
	}
	
	static int total(int[] arr) {
		int total = 0;
		
		for (int i: arr) {
			total += i;
		}
		
		return total;
	}
}
