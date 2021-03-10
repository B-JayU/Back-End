package stream;

import java.util.Arrays;
import java.util.stream.IntStream;

public class IntArrayTest {

	public static void main(String[] args) {
		
		int[] arr = {1,2,3,4,5,};
		
		IntStream stream = Arrays.stream(arr);
		int sum = Arrays.stream(arr).sum();
		System.out.println(sum);
		
		// �ڷῡ ���� ��Ʈ���� �����Ͽ� ������ �����ϸ� ��Ʈ���� �Ҹ��.
		// �ٸ� ������ ���ؼ��� ���ο� ��Ʈ���� ������.
		// ����, ��Ʈ���� �ѹ� �����ϰ� ����� �Ŀ��� ���� �� �� ����.
		
		int count = (int) Arrays.stream(arr).count();
		System.out.println(count);
	}

}
