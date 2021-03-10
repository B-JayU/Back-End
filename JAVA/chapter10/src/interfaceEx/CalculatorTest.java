package interfaceEx;

public class CalculatorTest {

	public static void main(String[] args) {
		
		int num1 = 10;
		int num2 = 2;
		
		Calc calc = new CompleteCalc();
		
		System.out.println(calc.add(num1, num2));
		//calc.showInfo();
		// CompleteCalc 클래스에 showInfo() 메소드가 존재하지만, Calc 클래스로 업캐스팅했으므로 사용할 수 없다.
		
		calc.description();
		
		int arr[] = {1,2,3,4,5};
		int sum = Calc.total(arr);
		System.out.println("Calc 계산기 total 결과 : " + sum);
		
	}
}
