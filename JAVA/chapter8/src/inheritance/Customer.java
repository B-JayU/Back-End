package inheritance;

public class Customer {
	
	protected int customerID;
	protected String customerName;
	protected String customerGrade;
	int bonusPoint;
	double bonusRatio;

	//protected ���� ��Ű��, ���
	//default ���� ��Ű��, ����Ŭ������ �ȵ�.
	//public �� ����
	
	public String getCustomerName() {
		return customerName;
	}

	public void setCustomerName(String customerName) {
		this.customerName = customerName;
	}

	public Customer() {
		customerGrade = "SILVER";
		bonusRatio = 0.01;
		
		System.out.println("Customer() ȣ��");
	}
	
	public Customer(int customerID, String customerName) {
		this.customerID = customerID;
		this.customerName = customerName;
		this.customerGrade = "SILVER";
		this.bonusRatio = 0.01;
	}
	
	public int calcPrice(int price) {
		
		
		if(customerGrade == "SILVER") {
			bonusPoint += price * bonusRatio;
		}else if(customerGrade == "VIP") {
			bonusPoint += price * bonusRatio;
		}else if(customerGrade == "GOLD") {
			bonusPoint += price * bonusRatio;
		}
		
		return price;
	}
	
	public String showCustomerInfo() {
		return customerName + " ���� ����� " + customerGrade + "�̸�, ���ʽ� ����Ʈ�� " + bonusPoint + "�Դϴ�.";
	}

	public int getCustomerID() {
		return this.customerID;
	}
	
	public void setCustomerID(int customerID) {
		this.customerID = customerID;
	}
	
	
	
	
	
	
	
}
