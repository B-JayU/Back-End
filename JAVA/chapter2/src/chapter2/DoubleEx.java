package chapter2;

public class DoubleEx {
	
	int abc;
	
	public static void main(String[] args) {
		double dNum = 3.14;
		float fNum = 3.14F; // 실수(8바이트) 데이터를 float형(4바이트)로 저장해라! 변수값 뒤에 F 병기
		
		System.out.println(dNum);
		
		var num = 10; 
		System.out.println(num);
		
		// num = 3.14; // 컴파일러가 앞선 데이터 10 저장으로 인해 num 변수를 int형으로 추론함.
					// 따라서 3.14(double) 데이터를 저장할 수 없음.
				
	}

}
