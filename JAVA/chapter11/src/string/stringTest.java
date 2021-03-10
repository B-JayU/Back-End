package string;

public class stringTest {

	public static void main(String[] args) {
		
		String str1 = new String("abc");
		String str2 = new String("abc");
		
		System.out.println(str1 == str2);
		System.out.println(str1.equals(str2));
		
		String str3 = "abc";
		String str4 = "abc";
		System.out.println(str3 == str4);
		
		String str01 = new String("java");
		String str02 = new String("android");
		
		System.out.println(System.identityHashCode(str01));
		
		str01 = str01.concat(str02);
		
		System.out.println(str01);
		System.out.println(System.identityHashCode(str01));
	}

}
