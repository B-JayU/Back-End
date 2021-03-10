// ���� ū ���� ã�Ƽ� ���� ���� �����Ϳ� ��ȯ(exchange)
public class selectionSort {

	static int[] ary = {29, 10, 14, 37, 13};
	static int length_a;
	
	public static void main(String[] args) {
		
		length_a = ary.length;
		
		int max_index=length_a-1;
		int max, temp;
		
		System.out.println("Before Sorting");
		showArray();
		
		for (int i = length_a-1; i > 0; i--) {
			max = ary[0];
			max_index = 0;
			for (int j = 1; j <=i; j++) {
				if (max < ary[j]) { 
					max = ary[j];
					max_index = j;
				}
			}
			 
			// �ִ밪�� ���� �����ʿ� �ִ� ���� exchange
			temp = ary[i];
			ary[i] = ary[max_index];
			ary[max_index] = temp;
		}
		
		System.out.println("After Sorting");
		showArray();
	}
	
	public static void showArray() {
		
		for (int i = 0; i < length_a; i++) {
			System.out.print(ary[i] + " ");
		}
		System.out.println();
	}
}
