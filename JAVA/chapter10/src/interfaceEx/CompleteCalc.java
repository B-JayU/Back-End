package interfaceEx;

public class CompleteCalc implements Calc{

	@Override
	public int add(int num1, int num2) {
		return num1+num2;
	}

	@Override
	public int substract(int num1, int num2) {
		return num1-num2;
	}
	
	@Override
	public int times(int num1, int num2) {
		return num1*num2;
	}

	@Override
	public int divide(int num1, int num2) {
		if (num2 != 0) {
			return num1/num2;
		}
			return ERROR;
	}
	
	public void showInfo() {
		System.out.println("Calc 인터페이스를 구현하였습니다.");
	}
	
	public void description() {
		System.out.println("완벽한 계산기 입니다.");
	}
}
