package others;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;

public class RandomAccessFileTest {

	public static void main(String[] args) throws IOException {
		
		RandomAccessFile rf = new RandomAccessFile("random.txt", "rw");
		rf.writeInt(100); // 4
		System.out.println(rf.getFilePointer());
		rf.writeDouble(3.14); // 4 + 8
		System.out.println(rf.getFilePointer());
		rf.writeUTF("æ»≥Á«œººø‰"); // 
		System.out.println(rf.getFilePointer());
		
		rf.seek(0);
		
		int i = rf.readInt();
		double d = rf.readDouble();
		String str = rf.readUTF();
		
		System.out.println(i);
		System.out.println(d);
		System.out.println(str);
		
	}

}
