package abstractEx;

public class ComputerTest {

	public static void main(String[] args) {
		
		// abstact 클래스는 new() instance화 할 수 없다. 
		/*Computer c1 = new Computer();
		c1.display();
		*/
		
		//computer는 추상 클래스이나, 하위클래스인 DeskTop과 MyNotebook는 정형화된 클래스임.
		// 이를 상위클래스인 Computer와 Notebook으로 업캐스팅 할 수 있음.
		
		// 상위클래스 : 어떻게 보여주겠다.
		// 하위클래스  : 구체적으로 어떻게 보여주겠다 
		
		Computer c2 = new DeskTop();
		Computer c3 = new MyNotebook();
		Notebook c4 = new MyNotebook();
		
		c2.display();
		c3.turnOn();
		c4.typing();
	}

}
