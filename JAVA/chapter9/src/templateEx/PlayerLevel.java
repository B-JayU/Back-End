package templateEx;

public abstract class PlayerLevel {
	
	//각 레벨마다 run(), jump(), turn() 기능은 다르게 구현되어야 하므로
	// 추상메서드로 선언함.
	public abstract void run();
	public abstract void jump();
	public abstract void turn();
	public abstract void showLevelMessage();
	
	// final로 선언된 go() method에서 각 순서와 반복 횟수를 구현함(template method)
	// 재정의되면 안되므로 final로 선언함. 
	final public void go(int count) {
		run();
		
		for(int i = 0; i < count; i++) {
			jump();
		}
		
		turn();
	}
}
