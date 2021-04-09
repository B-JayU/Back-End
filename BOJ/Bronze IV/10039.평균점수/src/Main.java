import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int score, sum = 0;
		
		for (int i = 0; i <5; i++) {
			score = sc.nextInt();
			
			if (score < 40)
				sum+= 40;
			else
				sum+=score;
		}
		
		System.out.println(sum/5);

	}

}
