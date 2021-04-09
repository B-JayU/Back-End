import java.util.Scanner;


class Main {

	static int div = 6;
	
	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);
		
		int jersey = keyboard.nextInt();
		int comb = (jersey-1) * (jersey-2) * (jersey-3);
		
		
		
		System.out.println(comb/div);
	}

}
