package inheritance;

public class GoldCustomer extends Customer{ // ��Ӱ� ���õǾ� ����Ŭ�������� ����Ŭ������ ������ �̸��� �޼ҵ带
											// ������ �ϴ°��� overriding(�������̵�)�̶�� �Ѵ�.

	public GoldCustomer() {
		bonusRatio = 0.3;
	}
	
	public int calcPrice(int price) {
		return super.calcPrice(price);
	}

}