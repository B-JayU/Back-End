package interfaceEx;

public class Customer implements Buy, Sell{

	@Override
	public void sell() {
		System.out.println("�Ǹ��ϱ�");
	}

	@Override
	public void buy() {
		System.out.println("�����ϱ�");
	}

	@Override
	public void order() {
		// TODO Auto-generated method stub
		System.out.println("�� �Ǹ� �ֹ�");
	}
	
	
	
}