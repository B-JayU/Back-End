package innerclass;

class Outer{

	int outNum = 100;
	static int sNum = 200;
	
	// �͸� innerClass ��� �󵵰� ŭ
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
		
		// outerŬ������ ������ �������̽� ���� method�� ȣ��
		// runnable �������̽� ��ü�� �����ϴ� ���� �ƴ϶�, �� ��� anonymous interface�� �����θ� �ٷ� �ۼ�
		outClass.runnable.run();
	}
}
