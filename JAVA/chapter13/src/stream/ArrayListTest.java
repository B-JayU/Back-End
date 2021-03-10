package stream;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;

public class ArrayListTest {

	public static void main(String[] args) {
		
		List<String> sList = new ArrayList<String>();
		sList.add("Tomas");
		sList.add("James");
		sList.add("Edward");
		
		Stream<String> stream = sList.stream();
		stream.forEach(s->System.out.println(s));
		
		// stream은 재사용 불가하므로 새롭게 생성해서 사용해야함.
		sList.stream().sorted().forEach(s->System.out.println(s));
		
		for( String s : sList) {
			System.out.println(s);
		}
	}
}
