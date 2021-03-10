package innerclass;

class Outer{

	int outNum = 100;
	static int sNum = 200;
	
	// 익명 innerClass 사용 빈도가 큼
	Runnable runnable = new Runnable() {

		@Override
		public void run() {
			System.out.println("runnable");
		}
	};
	
	
	Runnable getRunnable(int i) {
		
		int localNum = 100;
		class MyRunnable implements Runnable{

			@Override
			public void run() {
				
				System.out.println(outNum);
				System.out.println(sNum);
				System.out.println(localNum);
			}
			
		}
		return new MyRunnable();
	}
}

public class LocalInnerTest {

	public static void main(String[] args) {
		
		Outer outClass = new Outer();
		Runnable runnable = outClass.getRunnable(20);
		runnable.run();
		
		// outer클래스의 구현된 인터페이스 내의 method를 호출
		// runnable 인터페이스 객체를 생성하는 것이 아니라, 그 즉시 anonymous interface로 구현부를 바로 작성
		outClass.runnable.run();
	}
}
