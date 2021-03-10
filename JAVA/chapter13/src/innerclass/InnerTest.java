package innerclass;

class OutClass{
	
	private int num = 10;
	private static int sNum = 20;
	InClass inClass;
	
	public OutClass(){
		inClass = new InClass();
	}
	
	class InClass{
		int inNum = 200;
		
		void inTest() {
			System.out.println(num);
			System.out.println(sNum);
			System.out.println(inNum);
		}
		
	}
	
	static class InStaticClass{
		int iNum = 100;
		static int sInNum = 200;
		
		void inTest() {
			sNum += 10;
			System.out.println(sNum);
			System.out.println(iNum);
			System.out.println(sInNum);
		}
		
		static void sTest() {
			System.out.println(sNum);
			System.out.println(sInNum);
		}
	}
}

public class InnerTest {

	public static void main(String[] args) {
		
		OutClass outClass = new OutClass();
		outClass.inClass.inTest();
		
		// 내부클래스의 일반 메소드는 객체생성 이후에 호출해야 한다. 
		OutClass.InStaticClass sInClass = new OutClass.InStaticClass();
		sInClass.inTest();
		
		// static method는 클래스 객체 생성없이 호출가능
		OutClass.InStaticClass.sTest();
	}

}
