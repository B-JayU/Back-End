package exception;

public class IDFormatTest {
	
	private String userID;
	
	
	public String getUserID() {
		return userID;
	}


	public void setUserID(String userID) throws IDFormatException {
		
		if(userID == null) {
			throw new IDFormatException("�ƾƵ�� null �� �� �����ϴ�.");
		}else if(userID.length() < 8 || userID.length() > 20) {
			throw new IDFormatException("�ƾƵ�� 8�� �̻� 20�� ���Ϸ� ������.");
		}
		this.userID = userID;
	}


	public static void main(String[] args) {
		
		IDFormatTest idTest = new IDFormatTest();
		String userID = null;
		
		try {
			idTest.setUserID(userID);
		} catch (IDFormatException e) {
			System.out.println(e);
		}
		
		userID = "ByeongJu is very handsome guy";
		try {
			idTest.setUserID(userID);
		} catch (IDFormatException e) {
			System.out.println(e);
		}
	}
}
