import java.util.Scanner;

class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int T, min5, min1, sec10;
		
		T = sc.nextInt();
		
		min5 = T/300;
		T %= 300;
		
		min1 = T/60;
		T %= 60;
		
		sec10 = T/10;
		T %= 10;
		
		if (T == 0)
			System.out.println(min5 + " " + min1 + " " + sec10);
		else
			System.out.println("-1");
		
	}

}
