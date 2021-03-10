package array;

public class arrayTest {

	public static void main(String[] args) {
		
		// int[] numbers = new int[10];
		int[] numbers = new int[] {0,1,2};
		// 초기화 할때, array_size 는 생략해야한다.
		int[] numbers2 = {0,1,2};
		
		System.out.println(numbers.length);
		System.out.println(numbers2.length);
		
		int[] num = new int[3];
		num[0] = 1;
		num[1] = 2;
		num[2] = 3;
		
		for (int i = 0; i <num.length; i++) {
			System.out.println(num[i]);
		}
		
		// 정수형 배열은 initialize 하지 않으면, default value(0)으로 초기화
		int[] studentID = new int[5];
		for (int i = 0; i <studentID.length; i++) {
			System.out.println(studentID[i]);
		}
		
		
		
	}

}
