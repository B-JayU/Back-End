package array;

public class arrayTest3 {

	public static void main(String[] args) {
		
		char[] alphabet = new char[26];
		char ch = 'A';
		
		for (int i = 0; i < alphabet.length; i++, ch++) {
			alphabet[i] = ch;
		}
		
		for (int i = 0; i < alphabet.length; i++) {
			System.out.println(alphabet[i]);
		}
		
	}

}
