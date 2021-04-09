import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int xCharge= sc.nextInt();
		int yBase = sc.nextInt();
		int yUpperbound = sc.nextInt(); 
		int yCharge = sc.nextInt(); 
		int p = sc.nextInt();
		
		int xResult = 0, yResult = 0;
		
		xResult = p * xCharge;
		
		if (p <= yUpperbound)
			yResult = yBase; 
		else
			yResult = yBase + (p-yUpperbound) * yCharge;
		
		if (xResult <= yResult) {
			System.out.println(xResult);
		}else {
			System.out.println(yResult);
		}

	}

}
