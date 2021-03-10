package classEx;

public class ClassTest {

	public static void main(String[] args) throws ClassNotFoundException {
		
		Person person = new Person();
		
		// 1. getClass() �޼��� ����ϱ�
		Class pClass1 = person.getClass();
		System.out.println(pClass1.getName());
		
		// 2. Ŭ���� ���� �̸��� Class ������ ���� �����ϱ�
		Class pClass2 = Person.class;
		System.out.println(pClass2.getName());
	
		// 3. Class.forName("Ŭ���� �̸�")�޼��� ����ϱ�
		// ���� loading
		Class pClass3 = Class.forName("java.lang.String");
		System.out.println(pClass3.getName());
	}

}
