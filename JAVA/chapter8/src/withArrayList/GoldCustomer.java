package withArrayList;

public class GoldCustomer extends Customer{
	
	double saleRatio;
	public GoldCustomer(int customerID, String customerName) {
		
		super(customerID, customerName);
		customerGrade = "Gold";
		bonusRatio = 0.02;
		saleRatio = 0.01;
	}
	
	@Override
	public int calcPrice(int price) {
		bonusPoint += price * bonusRatio;
		return price - (int)(price * saleRatio);
	}
	
	
	
}
