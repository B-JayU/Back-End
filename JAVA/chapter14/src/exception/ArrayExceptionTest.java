package exception;

public class ArrayExceptionTest {

	public static void main(String[] args) {
		
		int[] arr = {1,2,3,4,5};
		try {
			for (int i = 0; i <=5; i++)
				System.out.println(arr[i]);
		}catch(ArrayIndexOutOfBoundsException e) {
			// exception log 
			System.out.println(e.toString());
			return;
		}finally { // try가 수행되면 반드시 수행되는 부분
			System.out.println("finally");
		}
		System.out.println("End");
	}
}
