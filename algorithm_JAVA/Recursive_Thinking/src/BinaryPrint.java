import java.util.Scanner;

public class BinaryPrint {

	public static void main(String[] args) {
		
		int num;
		Scanner keyboard = new Scanner(System.in);
		
		System.out.println("2���� ��ȯ ����ϱ�");
		System.out.print("10������ �Է��Ͻÿ� : ");
		num = keyboard.nextInt();

		System.out.print(num + "---- 2���� ��ȯ ----> ");
		printInBinary(num);
		System.out.println("(2)");
	}
	
	public static void printInBinary(int n) {
	
		//base case
		if (n <= 1)
			System.out.print(n);
		else {
			printInBinary(n/2);
			System.out.print(n%2);
		}
		
	}

}
