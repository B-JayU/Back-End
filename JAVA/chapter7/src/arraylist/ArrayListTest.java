package arraylist;

import java.util.ArrayList;

public class ArrayListTest {

	public static void main(String[] args) {
		
		ArrayList<String> list = new ArrayList<String>();
		list.add("aaa");
		list.add("bbb");
		list.add("ccc");
		
		for (String s : list) {
			System.out.println(s);
		}
		
		for (int i =0; i < list.size(); i++) {
			System.out.println(list.get(i));
		}
		// ArrayList는 인덱스를 제공하지 않는다.
		
	}

}
