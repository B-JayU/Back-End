package inheritance;

public class Customer {
	
	protected int customerID;
	protected String customerName;
	protected String customerGrade;
	int bonusPoint;
	double bonusRatio;

	//protected 같은 패키지, 상속
	//default 같은 패키지, 하위클래스는 안됨.
	//public 다 가능
	
	public String getCustomerName() {
		return customerName;
	}

	public void setCustomerName(String customerName) {
		this.customerName = customerName;
	}

	public Customer() {
		customerGrade = "SILVER";
		bonusRatio = 0.01;
		
		System.out.println("Customer() 호출");
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
		return customerName + " 님의 등급은 " + customerGrade + "이며, 보너스 포인트는 " + bonusPoint + "입니다.";
	}

	public int getCustomerID() {
		return this.customerID;
	}
	
	public void setCustomerID(int customerID) {
		this.customerID = customerID;
	}
	
	
	
	
	
	
	
}
