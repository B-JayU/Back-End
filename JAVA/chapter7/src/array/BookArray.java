package array;

public class BookArray {

	public static void main(String[] args) {
		
		Book[] shelf = new Book[5];
		Book[] bookArray1 = new Book[3];
		Book[] bookArray2 = new Book[3];
		
		
		// 객체 배열은 초기화 하지 않으면 null이 default값인 채로 생성된다
		
		/*
		for (int i= 0; i < shelf.length; i++) {
			System.out.println(shelf[i]);
		}
		*/
		
		bookArray1[0] = new Book("태백산맥1", "조정래");
		bookArray1[1] = new Book("태백산맥2", "조정래");
		bookArray1[2] = new Book("태백산맥3", "조정래");
		
		
		System.arraycopy(bookArray1, 0, bookArray2, 0, 3);
		
		for (int i = 0; i < bookArray2.length; i++) {
			bookArray2[i].showBookInfo();
		}
		
		System.out.println("----------------------");
		
		bookArray1[0].setBookName("나목");
		bookArray1[0].setAuthor("박완서");
		
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
		
		System.out.println("---------깊은 복사---------");
		for (int i = 0; i < bookArray1.length; i++) {
			bookArray3[i].setBookName(bookArray1[i].getBookName());
			bookArray3[i].setAuthor(bookArray1[i].getAuthor());
		}
		
		System.out.println("깊은 복사Book1---------");
		for (int i = 0; i < bookArray1.length; i++) {
			bookArray1[i].showBookInfo();
		}
		
		System.out.println("깊은 복사Book3---------");
		for (int i = 0; i < bookArray3.length; i++) {
			bookArray3[i].showBookInfo();
		}
	}
}
