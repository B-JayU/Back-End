package classEx;

public class ClassTest {

	public static void main(String[] args) throws ClassNotFoundException {
		
		Person person = new Person();
		
		// 1. getClass() 메서드 사용하기
		Class pClass1 = person.getClass();
		System.out.println(pClass1.getName());
		
		// 2. 클래스 파일 이름을 Class 변수에 직접 대입하기
		Class pClass2 = Person.class;
		System.out.println(pClass2.getName());
	
		// 3. Class.forName("클래스 이름")메서드 사용하기
		// 동적 loading
		Class pClass3 = Class.forName("java.lang.String");
		System.out.println(pClass3.getName());
	}

}
