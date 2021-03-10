package stream.inputstream;

import java.io.FileInputStream;
import java.io.IOException;

public class FileInputStreamTest {

	public static void main(String[] args) {
		
		FileInputStream fis = null;
		try {
			fis = new FileInputStream("input.txt");
			
			System.out.println(fis.read());
			System.out.println(fis.read());
			System.out.println(fis.read());
		} catch( IOException e) {
			System.out.println(e);
		}finally {
			try {
				fis.close();
			}catch (Exception e) {
				System.out.println(e);
			}
		}
		System.out.println("End");
	}

}
