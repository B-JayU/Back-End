
public class code02 {
	
	public static void main(String[] args) {
		int n = 4;
		func(n);
	}
	
	public static void func(int k) {
		
		// recursion Function
		
		// Set termination condition
		if (k <= 0) // base case : ��� �ϳ��� recursion�� ������ �ʴ� ��찡 �����ؾ� �Ѵ�. 
			return;
		else {
			System.out.println("hello~");
			func(k-1); // recursive case : recursion�� �ݺ��ϴٺ��� �ᱹ base case�� �����ؾ� �Ѵ�.
		}
	}
}
