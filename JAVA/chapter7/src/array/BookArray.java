package array;

public class BookArray {

	public static void main(String[] args) {
		
		Book[] shelf = new Book[5];
		Book[] bookArray1 = new Book[3];
		Book[] bookArray2 = new Book[3];
		
		
		// ��ü �迭�� �ʱ�ȭ ���� ������ null�� default���� ä�� �����ȴ�
		
		/*
		for (int i= 0; i < shelf.length; i++) {
			System.out.println(shelf[i]);
		}
		*/
		
		bookArray1[0] = new Book("�¹���1", "������");
		bookArray1[1] = new Book("�¹���2", "������");
		bookArray1[2] = new Book("�¹���3", "������");
		
		
		System.arraycopy(bookArray1, 0, bookArray2, 0, 3);
		
		for (int i = 0; i < bookArray2.length; i++) {
			bookArray2[i].showBookInfo();
		}
		
		System.out.println("----------------------");
		
		bookArray1[0].setBookName("����");
		bookArray1[0].setAuthor("�ڿϼ�");
		
		for (int i = 0; i < bookArray1.length; i++) {
			bookArray1[i].showBookInfo();
		}
		System.out.println("----------------------");
		
		for (int i = 0; i < bookArray2.length; i++) {
			bookArray2[i].showBookInfo();
		}
		
		Book[] bookArray3 = new Book[3];
		for (int i = 0; i < bookArray3.length; i++) {
			bookArray3[i] = new Book();
		}
		
		System.out.println("---------���� ����---------");
		for (int i = 0; i < bookArray1.length; i++) {
			bookArray3[i].setBookName(bookArray1[i].getBookName());
			bookArray3[i].setAuthor(bookArray1[i].getAuthor());
		}
		
		System.out.println("���� ����Book1---------");
		for (int i = 0; i < bookArray1.length; i++) {
			bookArray1[i].showBookInfo();
		}
		
		System.out.println("���� ����Book3---------");
		for (int i = 0; i < bookArray3.length; i++) {
			bookArray3[i].showBookInfo();
		}
	}
}
