package inheritance;

public class GoldCustomer extends Customer{ // 상속과 관련되어 하위클래스에서 상위클래스와 동일한 이름의 메소드를
											// 재정의 하는것은 overriding(오버라이딩)이라고 한다.

	public GoldCustomer() {
		bonusRatio = 0.3;
	}
	
	public int calcPrice(int price) {
		return super.calcPrice(price);
	}

}