import java.util.Scanner;

class Main {

	public static void main(String[] args) {
		
		Scanner keyboard = new Scanner(System.in);
		int[] depth = new int[4];
		boolean rising=false, diving=false, constant=false;
		int index;
		
		// input depth data by typing keyboard.
		for (int i = 0; i < 4; i++) {
			depth[i] = keyboard.nextInt();
		}
		
		// Rising
		if (depth[0] < depth[1]) {
			index = 1;
			while(index <= 2 && depth[index] < depth[index+1])
				index++;
			
			if(index == 3)
				rising = true;
		}
		
		// Diving
		else if (depth[0] > depth[1]) {
			index = 1;
			while(index <= 2 && depth[index] > depth[index+1])
				index++;
			
			if(index == 3)
				diving = true;
		}
		
		// Constant
		else {
			index = 1;
			while(index <= 2 && depth[index] == depth[index+1])
				index++;
			
			if(index == 3)
				constant = true;
		}
		
		if (rising == true)
			System.out.println("Fish Rising");
		else if (diving == true)
			System.out.println("Fish Diving");
		else if (constant == true)
			System.out.println("Fish At Constant Depth");
		else
			System.out.println("No Fish");
		
	}

}
