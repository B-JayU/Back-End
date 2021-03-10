package collection.arraylist;

import java.util.ArrayList;
import java.util.Iterator;

import collection.Member;

public class MemberArrayList {
	
	private ArrayList<Member> arrayList;
	
	//Generator
	public MemberArrayList() {
		arrayList = new ArrayList<Member>();
	}
	
	public void addMember(Member member) {
		arrayList.add(member);
	}
	
	public boolean removeMember(int memberId) {
		
		/*for( int i = 0; i < arrayList.size(); i++) {
			Member member = arrayList.get(i);
			
			if (member.getMemberId() == memberId) {
				arrayList.remove(i);
				System.out.println("�ش� memberId�� ���� ������ �����Ǿ����ϴ�.");
				return true;
			}
		}
		System.out.println("�ش� memberID�� �������� �ʽ��ϴ�.");
		return false;*/
		
		Iterator<Member> iterator = arrayList.iterator();
		while(iterator.hasNext()) {
			Member member = iterator.next();
			
			int tempId = member.getMemberId();
			if( memberId == tempId ) {
				arrayList.remove(member);
				return true;
			}
		}
		return false;
	}
	
	public void showAll() {
		
		for (Member member : arrayList) {
			System.out.println(member);
		}
		
		//System.out.println(arrayList);
	}
	
}
