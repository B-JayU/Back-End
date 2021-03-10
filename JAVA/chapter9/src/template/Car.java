package template;

public abstract class Car {

	public abstract void drive();
	public abstract void stop();
	public abstract void wiper();
	
	// ����Ŭ�������� �����Ǹ� �ʿ�� �ϴ� method
	// {} : ���� �κ�, ������ ���� �ڵ�� �������� ����.
	public void washCar() {};
	
	public void startCar() {
		System.out.println("�õ��� �̴ϴ�.");
	}
	
	public void turnOff() {
		System.out.println("�õ��� ���ϴ�.");
	}
	
	// final method : method�� �帧�� ������ ����. �Ϸ��� ������ �ó������� ���� method.
	public final void run() {
		startCar();
		drive();
		wiper();
		stop();
		washCar(); // �ʿ信 ���� �������ؼ� ����ϸ� �ȴ�.
		turnOff();
	}
}
