package reference;

public class StudentTest {

	public static void main(String[] args) {
		
		Student James = new Student(100, "James");
		James.setKorean("화법과작문",  85);
		James.setMath("기하와벡터",  97);
		James.setEnglish("실용영어",  93);
		
		James.showStudentInfo();
	}
}
