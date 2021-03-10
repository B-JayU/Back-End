package mergeSort;

public class MergeSort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		// original data array 생성
		int[] origin = {5,2,4,7,1,3,2,6};
		
		System.out.println("Before mergesort");
		showarray(origin);
		
		mergesort(origin, 0, 7);
		System.out.println("After mergesort");
		showarray(origin);
	}
	
	public static void mergesort(int[] a, int p, int r) {
		if (p < r) {
			int q = (p+r) /2; // 중간지점 계산
			mergesort(a,p,q); // 전반부 정렬
			mergesort(a,q+1,r); // 후반부 정렬
			merge(a,p,q,r); // 합병
		}
	}
	
	public static void merge(int[] a, int p, int q, int r) {
		
		int i = p, j = q+1, k = p;
		int[] temp = new int[a.length];
		
		while (i <= q && j <= r) {
			if (a[i] <= a[j]) 
				temp[k++] = a[i++];
			else
				temp[k++] = a[j++];
		}
		
		while(i <= q)
			temp[k++] = a[i++];
		while(j <= r)
			temp[k++] = a[j++];
		for (i =p; i <= r; i++)
			a[i] = temp[i];
	}
	
	public static void showarray(int[] a) {
		
		for (int i = 0; i < a.length; i++) {
			System.out.print(a[i] + " ");
		}
		System.out.println();
	}
}
