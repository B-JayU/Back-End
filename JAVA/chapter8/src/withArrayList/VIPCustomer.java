package withArrayList;

public class VIPCustomer extends Customer{
	
	private double saleRatio;
	private int agentID;

	public VIPCustomer() {
		
		super(); // ���� Ŭ������ ���� ����
		customerGrade = "VIP";
		bonusRatio = 0.05;
		saleRatio = 0.1;
		
		System.out.println("VIPCustomer() ȣ��");
	}
	
	public VIPCustomer(int customerID, String customerName, int agentID) {
		super(customerID, customerName);
		customerGrade = "VIP";
		bonusRatio = 0.05;
		saleRatio = 0.1;
		this.agentID = agentID;
	}
	
	public double getSaleRatio() {
		return saleRatio;
	}


	public void setSaleRatio(double saleRatio) {
		this.saleRatio = saleRatio;
	}

	public void setAgentID(int agentID) {
		this.agentID = agentID;
	}
	
	public int getAgentID() {
		return this.agentID;
	}
	
	public int calcPrice(int price) {
		bonusPoint += price * bonusRatio;
		return price - (int)(price * saleRatio);
	}
	
	public String showCustomerInfo() {
		return super.showCustomerInfo() + "��� ������ ���̵�� " + agentID + "�Դϴ�.";
	}
	
	
	
	
}