package thisEx;

class Person{
	
	String name;
	int age;
	
	public Person() {
		
		//생성자에서 다른 생성자를 부를때 this를 사용한다.
		// 이때 constructor 앞에 어떠한 코드도 올 수 없다.
		
		/*name = "이름없음";
		age = 1;
		*/
	
		this("이름없음", 1);
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
