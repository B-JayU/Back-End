package interfaceEx;

public interface Calc {

	// public static final ������ �����. ��������
	double PI = 3.14;
	int ERROR = -999999999;
	
	// interface �ȿ� default�� �����ϸ� public abstract method�� �ڵ� debugging ��.
	
	int add(int num1,int num2);
	int substract(int num1, int num2);
	int times(int num1, int num2);
	int divide(int num1, int num2);

	default void description() {
		System.out.println("���� ���⸦ ���մϴ�.");
	}
	
	static int total(int[] arr) {
		int total = 0;
		
		for (int i: arr) {
			total += i;
		}
		
		return total;
	}
}
