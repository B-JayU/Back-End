package abstractEx;

public class ComputerTest {

	public static void main(String[] args) {
		
		// abstact Ŭ������ new() instanceȭ �� �� ����. 
		/*Computer c1 = new Computer();
		c1.display();
		*/
		
		//computer�� �߻� Ŭ�����̳�, ����Ŭ������ DeskTop�� MyNotebook�� ����ȭ�� Ŭ������.
		// �̸� ����Ŭ������ Computer�� Notebook���� ��ĳ���� �� �� ����.
		
		// ����Ŭ���� : ��� �����ְڴ�.
		// ����Ŭ����  : ��ü������ ��� �����ְڴ� 
		
		Computer c2 = new DeskTop();
		Computer c3 = new MyNotebook();
		Notebook c4 = new MyNotebook();
		
		c2.display();
		c3.turnOn();
		c4.typing();
	}

}
