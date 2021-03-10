package quickSort;

public class QuickSort {

	static int[] ary = {15, 16, 48, 13, 95, 45, 76, 43};
	
	public static void main(String[] args) {
		
		System.out.println("Before quicksort");
		showarray(ary);
		
		quicksort(ary, 0, ary.length-1);
		
		System.out.println("After quicksort");
		showarray(ary);

	}
	
	public static void quicksort(int[] a, int p, int r) {
		int q;
		
		if (p < r) {
			q = partition(a, p, r);
			quicksort(ary, p, q-1);
			quicksort(ary, q+1, r);
		}
	}
	
	public static int partition(int[] a, int p, int r) {
		
		int pivot = a[r], lower=p-1;
		int temp;
		
		for (int i = p; i <r; i++) {
			if (a[i] <= pivot)
			{
				lower++;
				temp = a[i]; 
				a[i] = a[lower];
				a[lower] = temp;
			}
		}
		
		for (int i = r-1; i > lower; i--)
			a[i+1] = a[i];
		
		a[lower+1] = pivot;
		
		return lower+1;
	}
	
	public static void showarray(int[] a) {
		
		for (int i = 0; i < a.length; i++) {
			System.out.print(a[i] + " ");
		}
		System.out.println();
	}

}
