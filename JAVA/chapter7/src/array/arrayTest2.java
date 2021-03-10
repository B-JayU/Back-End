package array;

public class arrayTest2 {

	public static void main(String[] args) {
		
		double[] num = new double[5];
		
		// size은 유효한 데이터의 값
		// default value : 유효하지 않은 데이터
		
		int size = 0;
		num[0] = 10.0; size++;
		num[1] = 20.0; size++;
		num[2] = 30.0; size++;
		
		double total  = 1.0;
		for (int i = 0; i < num.length; i++) {
			total *= num[i];
		}
	
		System.out.println("total = " + total);
		
		
		total = 1.0;
		for (int i = 0; i < size; i++) {
			total *= num[i];
		}
		
		System.out.println("total = " + total);	
	}
}
