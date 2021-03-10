package classEx;

import java.lang.reflect.Constructor;

public class StringTest {

	public static void main(String[] args) throws ClassNotFoundException {
		
		Class strClass = Class.forName("java.lang.String");
		
		Constructor[] cons = strClass.getConstructors();
		
		for (Constructor c: cons) {
			System.out.println(c);
		}
	}
}
