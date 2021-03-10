package loopExample;

public class ContinueExample {

	public static void main(String[] args) {
		int total = 0;
		int num;
		
		for (num = 1; num <= 100; num++) {
			if (num % 2 == 1) 
				continue;
			total += num;
		}
	}

}
