package reference;

public class Student {

	int studentID;
	String studentName;
	/*
	int KoreanScore;
	int mathScore;
	String KoreanSubject;
	String mathSubject;
	
	int engScore;
	String engSubject;
	*/
	
	Subject korean;
	Subject math;
	Subject english;
	
	public Student() {
		korean = new Subject();
		math = new Subject();
		english = new Subject();
		
	}
	
	public Student(int id, String name) {
		studentID = id;
		studentName = name;
		
		korean = new Subject();
		math = new Subject();
		english = new Subject();
		
	}
	
	public void setKorean(String name, int score) {
		korean.setSubjectName(name);
		korean.setScore(score);
	
	}
	
	public void setMath(String name, int score) {
		math.setSubjectName(name);
		math.setScore(score);
	
	}
	
	public void setEnglish(String name, int score) {
		english.setSubjectName(name);
		english.setScore(score);
	
	}
	
	public void showStudentInfo() {
		int total = korean.getScore() + math.getScore() + english.getScore();
		System.out.println(studentName+"의 총점은 " + total + "점입니다.");
		
	}
	

}
