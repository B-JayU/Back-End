package loopExample;

public class WhileExample {

	public static void main(String[] args) {
		
		int num = 1;
		int sum = 0;
		/*
		while( num <= 10) {
			sum += num;
			num++;
		}
		
		*/
		
		do {
			sum += num;
			num++;
		}while(num <= 10);
		
		System.out.println("1���� 10������ ���� " + sum + "�Դϴ�.");
	}

}