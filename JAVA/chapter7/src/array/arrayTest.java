package array;

public class arrayTest {

	public static void main(String[] args) {
		
		// int[] numbers = new int[10];
		int[] numbers = new int[] {0,1,2};
		// �ʱ�ȭ �Ҷ�, array_size �� �����ؾ��Ѵ�.
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
		
		// ������ �迭�� initialize ���� ������, default value(0)���� �ʱ�ȭ
		int[] studentID = new int[5];
		for (int i = 0; i <studentID.length; i++) {
			System.out.println(studentID[i]);
		}
		
		
		
	}

}
