package lambda;

public class TestStringConcat {

	public static void main(String[] args) {
		
		//객체지향 방식으로 구현하기
		StringConcatImpl sImpl = new StringConcatImpl();
		sImpl.makeString("hello", "java");
		
		// lambda식을 생성하고, 이에 대한 lambda식 호출하기
		StringConcat concat = (s1, s2) -> System.out.println(s1 + " " + s2);
		concat.makeString("hello",  "java");
		
		// anonymous inner class
		StringConcat concat2 = new StringConcat() {

			@Override
			public void makeString(String s1, String s2) {
				System.out.println(s1 + " " + s2);
			}
		};
		
		concat2.makeString("hello", "java");
	}

}
