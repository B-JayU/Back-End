package others;

import java.util.Scanner;

public class ScannerTest {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("String�� �Է��ϼ��� : ");
		String name = scanner.nextLine();
		
		System.out.print("���ڸ� �Է��ϼ��� : ");
		int num = scanner.nextInt();
		
		System.out.println(name);
		System.out.println(num);
	}

}
