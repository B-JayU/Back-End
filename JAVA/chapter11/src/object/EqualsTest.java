package object;

class Student{
	int studentID;
	String studentName;
	
	Student(int studentID, String studentName) {
		this.studentID = studentID;
		this.studentName = studentName;
	}

	public boolean equals(Object obj) {
		// ���޵� arg�� Student Ŭ������ instance���� Ȯ���� ��, ������ downCasting
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
		// hash Function �������ٴ� �������� ������ ��ü�� ���Ͽ� ������ hashcode ���� ��ȯ�ϵ��� �ϱ�.
		// equals�� ������ �Ҷ� ����� ��� �������� Ȱ���Ͽ� ��ȯ���� ���Ѵ�. 
		return this.studentID;
	}
	
	
	
}
public class EqualsTest {

	public static void main(String[] args) {
		
		Student stu1 = new Student(2018394293, "�輮��");
		Student stu2 = new Student(2018394293, "�輮��");
		
		System.out.println("�������� ���ϼ� Ȯ��");
		System.out.println(stu1 == stu2);
		
		System.out.println("==============");
		System.out.println("������ ���ϼ� Ȯ��");
		System.out.println(stu1.equals(stu2));
		
		System.out.println("===Hash Code===");
		System.out.println(stu1.hashCode());
		System.out.println(stu2.hashCode());
	}

}
