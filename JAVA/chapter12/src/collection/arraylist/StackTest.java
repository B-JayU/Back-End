package collection.arraylist;

import java.util.ArrayList;

class Mystack{
	
	private ArrayList<String> arrayStack = new ArrayList<String>();
	
	public void push(String data) {
		arrayStack.add(data);
	}
	
	public String pop() {
		int len = arrayStack.size();
		
		if (len <= 0) {
			System.out.println("������ ������ϴ�.");
			return null;
		}
		return  arrayStack.remove(len-1);
	}
	
	public String peek() {
		int len = arrayStack.size();
		
		if (len <= 0) {
			System.out.println("������ ������ϴ�.");
			return null;
		}
		return  arrayStack.get(len-1);
	}
	
	public void showAll() {
		
		System.out.println("Stack Ȯ���ϱ�(Stack size : " + arrayStack.size() + ")");
		for (String s : arrayStack) {
			System.out.println(s);
		}
	}
}
public class StackTest {
	
	public static void main(String[] args) {
		
		Mystack stackT = new Mystack();
		
		stackT.push("ABC");
		stackT.push("DEF");
		stackT.push("GHI");
		stackT.push("JKL");
		
		stackT.showAll();
		
		String rem = stackT.pop();
		
		if (rem == null) {
			System.out.println("popȣ���� ���� �� element�� �����ϴ�.");
		}else {
			System.out.println("Remove element : " + rem);
		}
		
		stackT.showAll();
	}
}
