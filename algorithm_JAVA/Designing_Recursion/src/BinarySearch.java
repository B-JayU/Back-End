import java.util.Scanner;

public class BinarySearch {
	
	public static void main(String[] args) {
	
		int[] set = {1,6,30,59,64,68,342};
		int szSet, findIdx, target;
		szSet = set.length;
		
		Scanner keyboard = new Scanner(System.in);
		
		System.out.print("Please input num to find : ");
		target = keyboard.nextInt();
		
		findIdx = binarySearch(set, target, 0, szSet-1);
		
		if(findIdx == -1) {
			System.out.println("Not exist");
		}
		else {
			System.out.println("Find Success : (Index : " + findIdx + ")");
		}
	}
	
	public static int binarySearch(int[] items, int target, int begin, int end) {
		if (begin > end)
			return -1;
		else {
			int middle = (begin + end)/2;
			if (target == items[middle])
				return middle;
			else if(target < items[middle])
				return binarySearch(items, target, begin, middle-1);
			else
				return binarySearch(items, target, middle+1, end);
		}
	}
	
}
