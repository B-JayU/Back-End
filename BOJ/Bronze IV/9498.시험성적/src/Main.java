import java.util.Scanner;

class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int score = sc.nextInt()/10;
		
		if (score >= 9)
			System.out.println("A");
		else if(score == 8)
			System.out.println("B");
		else if(score == 7)
			System.out.println("C");
		else if(score == 6)
			System.out.println("D");
		else
			System.out.println("F");

	}
}
