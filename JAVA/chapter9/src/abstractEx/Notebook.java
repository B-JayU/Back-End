package abstractEx;

public abstract class Notebook extends Computer{

	@Override
	public void display() {
		System.out.println("Excute Notebook display()");
	}

	@Override
	public abstract void typing();
}
