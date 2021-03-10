package chapter2;

public class ImplicitConversion {

	public static void main(String[] args) {
		byte bNum = 10;
		int num = bNum;
		
		System.out.println(bNum);
		
		long lNum = 10;
		float fNum = lNum;
		System.out.println(fNum);
		
		double dNum = fNum + num;
		System.out.println(dNum);
		
		int iNum = 1000;
		bNum = (byte)iNum;
		
		System.out.println(iNum);
		System.out.println(bNum); // ū �����Ϳ��� ���� ������������ ����ȯ�� ������ �ʴ� ������ �ս��� �߻��� �� �ִ�.
		
		dNum = 3.14;
		iNum = (int)dNum;
		System.out.println(iNum);
		
		fNum = 0.9F;
		
		int num1 = (int)dNum + (int)fNum;
		int num2 = (int)(dNum + fNum);
		
		System.out.println(num1);
		System.out.println(num2);
		
	}

}
