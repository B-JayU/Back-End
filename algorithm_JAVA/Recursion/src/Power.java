
public class Power {

	public static void main(String[] args) {
		
		double x=4, result;
		int n=5;
		
		result = power(x, n);
		System.out.println((int)x + "^" + n + "=" + (int)result);
	}
	
	public static double power(double x, int n) {
		if (n == 0)
			return 1;
		else {
			return x * power(x, n-1);
		}
	}

}
