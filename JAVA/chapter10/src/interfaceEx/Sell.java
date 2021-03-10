package interfaceEx;

public interface Sell {
	
	void sell();
	
	default void order() {
		System.out.println("구매주문");
	}
}
