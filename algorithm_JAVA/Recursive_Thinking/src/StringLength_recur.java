
public class StringLength_recur {

	public static void main(String[] args) {
		
		
		String strObj = "hello world!";
		int len = length(strObj);
		System.out.println(strObj + "의 길이는 " + len + "입니다.\n");
		
		System.out.print("Original show :");
		printChars(strObj);
		System.out.println("\n");
		
		System.out.println("Reverse show : ");
		printCharsReverse(strObj);
		System.out.println("\n");
		
	}
	
	public static int length(String str) {
		if (str.equals(""))
			return 0;
		else
			return 1 + length(str.substring(1));
	}
	
	public static void printChars(String str) {
		if (str.length() == 0) // baseCase
			return;
		else {
			System.out.println(str.charAt(0));
			printChars(str.substring(1));
		}
	}
	
	public static void printCharsReverse(String str) {
		if (str.length()==0) //baseCase
			return;
		else {
			printCharsReverse(str.substring(1));
			System.out.println(str.charAt(0));
		}
		
	}
}
