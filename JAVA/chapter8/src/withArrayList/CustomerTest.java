package withArrayList;

import java.util.ArrayList;

public class CustomerTest {

	public static void main(String[] args) {
		
		ArrayList<Customer> customerList = new ArrayList<Customer>();
		// Customer, VIPCustomer, GoldCustomer
		
		Customer customerLee = new Customer(10010, "�̼���");
		Customer customerShin = new Customer(10011, "�Ż��Ӵ�");
		GoldCustomer customerHong = new GoldCustomer(10012, "ȫ�浿");
		GoldCustomer customerYul = new GoldCustomer(10013, "������");
		VIPCustomer customerKim = new VIPCustomer(10014, "������", 30001);
		
		customerList.add(customerLee);
		customerList.add(customerShin);
		customerList.add(customerHong);
		customerList.add(customerYul);
		customerList.add(customerKim);
	
		System.out.println("======= ������ ��� ===");
		for (Customer customer : customerList) {
			System.out.println(customer.showCustomerInfo());
		}
		
		System.out.println("�������� ���ʽ� ����Ʈ ���");
		for (Customer customer : customerList) {
			int cost = customer.calcPrice(10000);
			
			System.out.println(customer.getCustomerName() + "���� " + cost +"�� �����ϼ̽��ϴ�.");
			System.out.println(customer.showCustomerInfo());
		}	
	}
}
