
public class factorial {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int n = 4, result;
		result = fact(n);
		System.out.printf("fact(%d) : %d\n", n, result);
	}
	
	public static int fact(int k) {
		if (k <= 1)
			return 1;
		else {
			return k * fact(k-1);
		}
	}
}
