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
		}finally { // try�� ����Ǹ� �ݵ�� ����Ǵ� �κ�
			System.out.println("finally");
		}
		System.out.println("End");
	}
}
