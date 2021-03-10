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
		
		// ����Ŭ������ �Ϲ� �޼ҵ�� ��ü���� ���Ŀ� ȣ���ؾ� �Ѵ�. 
		OutClass.InStaticClass sInClass = new OutClass.InStaticClass();
		sInClass.inTest();
		
		// static method�� Ŭ���� ��ü �������� ȣ�Ⱑ��
		OutClass.InStaticClass.sTest();
	}

}
