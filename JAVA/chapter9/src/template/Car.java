package template;

public abstract class Car {

	public abstract void drive();
	public abstract void stop();
	public abstract void wiper();
	
	// 하위클래스에서 재정의를 필요로 하는 method
	// {} : 구현 부분, 실제로 구현 코드는 존재하지 않음.
	public void washCar() {};
	
	public void startCar() {
		System.out.println("시동을 겁니다.");
	}
	
	public void turnOff() {
		System.out.println("시동을 끕니다.");
	}
	
	// final method : method의 흐름은 변하지 않음. 일련의 과정을 시나리오로 만든 method.
	public final void run() {
		startCar();
		drive();
		wiper();
		stop();
		washCar(); // 필요에 따라 재정의해서 사용하면 된다.
		turnOff();
	}
}
