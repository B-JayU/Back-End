package thisEx;

class Person{
	
	String name;
	int age;
	
	public Person() {
		
		//�����ڿ��� �ٸ� �����ڸ� �θ��� this�� ����Ѵ�.
		// �̶� constructor �տ� ��� �ڵ嵵 �� �� ����.
		
		/*name = "�̸�����";
		age = 1;
		*/
	
		this("�̸�����", 1);
	}
	
	public Person(String name, int age) {
		this.name = name;
		this.age = age;
	}
	 
	public  Person returnSelf() {
		return this;
	}
	
}
public class CallAnotherConst {

	public static void main(String[] args) {
		
		Person p1 = new Person();
		System.out.println(p1.name);
		System.out.println(p1);
		System.out.println(p1.returnSelf());
		
	}

}
