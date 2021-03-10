package object;

class Student{
	int studentID;
	String studentName;
	
	Student(int studentID, String studentName) {
		this.studentID = studentID;
		this.studentName = studentName;
	}

	public boolean equals(Object obj) {
		// 전달된 arg가 Student 클래스의 instance인지 확인한 후, 맞으면 downCasting
		if (obj instanceof Student) {
			Student s = (Student)obj; // DownCasting
			
			if (this.studentID == s.studentID && this.studentName == s.studentName) // logical equivalence
				return true;
			else
				return false;
			
		}else
			return false;
	}

	@Override
	public int hashCode() {
		// hash Function 구현보다는 논리적으로 동일한 객체에 대하여 동일한 hashcode 값을 반환하도록 하기.
		// equals를 재정의 할때 사용한 멤버 변수들을 활용하여 반환값을 정한다. 
		return this.studentID;
	}
	
	
	
}
public class EqualsTest {

	public static void main(String[] args) {
		
		Student stu1 = new Student(2018394293, "김석원");
		Student stu2 = new Student(2018394293, "김석원");
		
		System.out.println("물리적인 동일성 확인");
		System.out.println(stu1 == stu2);
		
		System.out.println("==============");
		System.out.println("논리적인 동일성 확인");
		System.out.println(stu1.equals(stu2));
		
		System.out.println("===Hash Code===");
		System.out.println(stu1.hashCode());
		System.out.println(stu2.hashCode());
	}

}
