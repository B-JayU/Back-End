import java.util.Scanner;

public class SequentialSearch {
	
	public static void main(String[] args) {
	
		int[] set = {1,3421,6,84,59,64,30,68,32};
		int szSet, num, maxV;
		szSet = set.length;
		
		System.out.println("Start Sequential Search");
		
		Scanner keyboard = new Scanner(System.in);
		System.out.print("Please input integer number to serarch : ");
		num = keyboard.nextInt();
		
		if (search(set, szSet, num) == -1) 
			System.out.println("Not exist!!!");
		else 
			System.out.println("location index : " + search(set, szSet, num));
		
		System.out.println("Find MAX Value");
		maxV = findMax(set, 0, szSet-1);
		System.out.println("Max Value : " + maxV);
		
		
	}
	
	public static int search(int[] data, int n, int target) {
		for (int i =0; i <n; i++)
			if (data[i]==target)
				return i;
		return -1;
	}
	
	// 매개변수의 명시화 : 순차 탐색 (ver.recursive)
	public static int search(int[] data, int begin, int end, int target) {
		if (begin > end)
			return -1;
		else if(target==data[begin])
			return begin;
		else
			return search(data, begin+1, end, target);
	}
	
	public static int findMax(int[] data, int begin, int end) {
		if (begin==end)
			return data[begin];
		else
			return Math.max(data[begin], findMax(data, begin+1, end));
	}
}
