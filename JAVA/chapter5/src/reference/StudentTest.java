package reference;

public class StudentTest {

	public static void main(String[] args) {
		
		Student James = new Student(100, "James");
		James.setKorean("ȭ�����۹�",  85);
		James.setMath("���Ͽͺ���",  97);
		James.setEnglish("�ǿ뿵��",  93);
		
		James.showStudentInfo();
	}
}
