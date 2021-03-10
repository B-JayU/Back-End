package singleton;

public class Company {
	
	private static Company instance = new Company();
	
	// 1. singleton 패턴이므로 클래스를 private하게 설정
	private Company() {}
	
	public static Company getInstance() {
		if (instance == null)
			instance = new Company();
		return instance;
	}
}
