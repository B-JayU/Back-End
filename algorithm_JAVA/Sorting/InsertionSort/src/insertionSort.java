// 두번째... n번쨰 까지
// 어느 위치에 삽입할 것인가
public class insertionSort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		// original data array 생성
		int[] origin = {5,2,4,7,1,3,2,6};
		
		System.out.println("Before insertionsort");
		showarray(origin);
		
		// 시작점, 현재지점, 끝지점
		
		for (int i = 1; i < origin.length; i++) {
			insertion(origin, 0, i, origin.length-1);
		}
		
		System.out.println("After insertionsort");
		showarray(origin);
	}
	
	public static void insertion(int[] a, int start, int cur, int end) {
		
		int index = cur-1, temp;
		
		if (cur > start) {
			while(index >= start && a[index] > a[cur]) {
				index--;
			}
		
			temp = a[cur];
		
			for (int i = cur-1; i > index ; i--) 
				a[i+1] = a[i];
		
			a[index+1] = temp;	
		}
		
	}
	
	public static void showarray(int[] a) {
		
		for (int i= 0; i < a.length; i++) 
			System.out.print(a[i] + " ");
		System.out.println();
	}

}
