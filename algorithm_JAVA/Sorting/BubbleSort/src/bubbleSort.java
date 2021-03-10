// 바로 옆에 있는 값과 비교하여 크면 오른쪽으로 이동 => 각 pass를 끝낼 때 마다 최대값이 오른쪽 끝에 위치하게 된다.

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
				if (ary[j-1] > ary[j] ) { // 이웃한 것끼리 exchange
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
