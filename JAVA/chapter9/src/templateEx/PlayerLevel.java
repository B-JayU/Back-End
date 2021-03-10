package templateEx;

public abstract class PlayerLevel {
	
	//�� �������� run(), jump(), turn() ����� �ٸ��� �����Ǿ�� �ϹǷ�
	// �߻�޼���� ������.
	public abstract void run();
	public abstract void jump();
	public abstract void turn();
	public abstract void showLevelMessage();
	
	// final�� ����� go() method���� �� ������ �ݺ� Ƚ���� ������(template method)
	// �����ǵǸ� �ȵǹǷ� final�� ������. 
	final public void go(int count) {
		run();
		
		for(int i = 0; i < count; i++) {
			jump();
		}
		
		turn();
	}
}
