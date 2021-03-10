
public class code02 {
	
	public static void main(String[] args) {
		int n = 4;
		func(n);
	}
	
	public static void func(int k) {
		
		// recursion Function
		
		// Set termination condition
		if (k <= 0) // base case : 적어도 하나의 recursion에 빠지지 않는 경우가 존재해야 한다. 
			return;
		else {
			System.out.println("hello~");
			func(k-1); // recursive case : recursion을 반복하다보면 결국 base case로 수렴해야 한다.
		}
	}
}
