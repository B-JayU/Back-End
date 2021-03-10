package stream;

import java.util.Arrays;
import java.util.stream.IntStream;

public class IntArrayTest {

	public static void main(String[] args) {
		
		int[] arr = {1,2,3,4,5,};
		
		IntStream stream = Arrays.stream(arr);
		int sum = Arrays.stream(arr).sum();
		System.out.println(sum);
		
		// 자료에 대한 스트림을 생성하여 연산을 수행하면 스트림은 소모됨.
		// 다른 연산을 위해서는 새로운 스트림을 생성함.
		// 따라서, 스트림은 한번 생상하고 사용한 후에는 재사용 할 수 없다.
		
		int count = (int) Arrays.stream(arr).count();
		System.out.println(count);
	}

}
