// �ٷ� ���� �ִ� ���� ���Ͽ� ũ�� ���������� �̵� => �� pass�� ���� �� ���� �ִ밪�� ������ ���� ��ġ�ϰ� �ȴ�.

public class bubbleSort {

	static int[] ary = {29, 10, 14, 37, 13};
	static int length_a;
	
	public static void main(String[] args) {
		
		int temp;
		length_a = ary.length;
		
		System.out.println("Before bubbleSort");
		showArray();
		
		for (int i = length_a-1; i > 0; i--) { // pass
			
			for (int j = 1; j <= i; j++) {
				if (ary[j-1] > ary[j] ) { // �̿��� �ͳ��� exchange
					temp = ary[j];
					ary[j] = ary[j-1];
					ary[j-1] = temp;
				}
			}
		}
		
		System.out.println("After bubbleSort");
		showArray();
	}
	
	public static void showArray() {
		
		for (int i = 0; i < length_a; i++) {
			System.out.print(ary[i] + " ");
		}
		System.out.println();
	}

}
