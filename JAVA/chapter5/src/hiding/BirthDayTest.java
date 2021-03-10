package hiding;

class BirthDay {
	
	private int day;
	private int month;
	private int year;
	public int getDay() {
		return day;
	}
	public void setDay(int day) {
		if (month == 2) {
			if (day <1 || day > 28) {
				System.out.println("날짜 입력 오류가 발생했습니다.");
			}
		}
		else {
			this.day = day;
		}
	}
		
	public int getMonth() {
		return month;
	}
	public void setMonth(int month) {
		
		this.month = month;
	}
	public int getYear() {
		return year;
	}
	public void setYear(int year) {
		this.year = year;
	}
	
}
 // 하나의 파일에 클래스가 여러개 있을수도 있음.

public class BirthDayTest{
	
	public static void main(String[] args) {
		
		BirthDay day = new BirthDay();
		day.setMonth(2);
		day.setDay(30); // 참 조 변수가 private 선언되었으므로, 직접 대입은 어렵고
		// public setter 함수를 이용하여 값을 대입한다.
		day.setYear(1998);
		
	}
}