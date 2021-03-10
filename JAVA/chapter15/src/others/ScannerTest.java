package others;

import java.util.Scanner;

public class ScannerTest {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("String을 입력하세요 : ");
		String name = scanner.nextLine();
		
		System.out.print("숫자를 입력하세요 : ");
		int num = scanner.nextInt();
		
		System.out.println(name);
		System.out.println(num);
	}

}
