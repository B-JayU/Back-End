package object;

public class objectCloneTest {

	public static void main(String[] args) throws CloneNotSupportedException {
		Circle circle = new Circle(10,20,5);
		Circle cloneCircle = (Circle)circle.clone();

		System.out.println(System.identityHashCode(circle));
		System.out.println(System.identityHashCode(cloneCircle));
		
		System.out.println(circle);
		System.out.println(cloneCircle);
	}

}
