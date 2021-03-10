package loopExample;

public class ForExample {

	public static void main(String[] args) {
		
		int num = 1;
		int sum = 0;
		
		while(num <= 10) {
			
			sum += num;
			num++;
		}
		System.out.println(sum);
		System.out.println(num);
		
		
		for (num =1, sum = 0; num <= 10; num++) {
			sum+= num;
		}
		
		System.out.println(sum);
		System.out.println(num);
	}

}
