package inheritance;

public class OverridingTest {

	public static void main(String[] args) {
		
		Customer customerLee = new Customer(100010, "Lee");
		int price = customerLee.calcPrice(10000);
		System.out.println(customerLee.customerName + "님의 지불금액 : " + price);
		System.out.println(customerLee.showCustomerInfo());
		
		VIPCustomer customerKim = new VIPCustomer(100010, "Kim");
		price = customerKim.calcPrice(10000);
		System.out.println(customerKim.customerName + "님의 지불금액 : " + price);
		System.out.println(customerKim.showCustomerInfo());
		
		Customer customerWho = new VIPCustomer(100010, "Who");
		price = customerWho.calcPrice(10000);
		System.out.println(customerWho.customerName + "님의 지불금액 : " + price);
		System.out.println(customerWho.showCustomerInfo());
		
	}

}
