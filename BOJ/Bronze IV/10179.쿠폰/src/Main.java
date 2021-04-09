import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int t_case = sc.nextInt();
		double[] origin = new double[t_case];
		
		for(int i = 0; i < t_case; i++) 
			origin[i] = sc.nextDouble();
		
		for (int i = 0; i < t_case; i++) 
			System.out.printf("$%.2f\n", origin[i]*0.8);
	}

}
