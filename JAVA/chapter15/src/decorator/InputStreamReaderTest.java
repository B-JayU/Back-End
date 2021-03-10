package decorator;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

public class InputStreamReaderTest {
	
	public static void main(String[] args) {
		
		try(InputStreamReader irs = new InputStreamReader(new FileInputStream("reader.txt") )){
			int i = 0;
			while((i= irs.read()) != -1) {
				System.out.print((char)i);
			}
		} catch (IOException e) {
			System.out.println(e);
		}
		
		/*Socket socket = new Socket();
		try {
			// InputStreamReader는 혼자서 읽어들일 수 없고 바이트단위를 문자단위로 변환하는 역할을 하는 스트림 클래스이다.
			BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			br.readLine();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}*/
		
	}
}
