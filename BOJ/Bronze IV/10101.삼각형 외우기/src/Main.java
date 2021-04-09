import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int[] tri_angle = new int[3];
		int angleSum = 0;
		
		for (int i = 0; i< 3; i++) {
			tri_angle[i] = sc.nextInt();
			angleSum += tri_angle[i];
		}
			
		
		if (angleSum == 180) {
			
			if (tri_angle[0] == 60 && tri_angle[1] == 60 && tri_angle[2] == 60)
				System.out.println("Equilateral");
			
			else if(angleSum == 180 && ((tri_angle[0] == tri_angle[1]) 
					|| (tri_angle[1] == tri_angle[2]) 
					|| (tri_angle[0] == tri_angle[2]))) {
				System.out.println("Isosceles");
			}
			
			else {
				System.out.println("Scalene");
			}
		}else
			System.out.println("Error");

	}

}
