package collection.arraylist;

import collection.Member;

public class MemberArrayListTest {

	public static void main(String[] args) {
		
		MemberArrayList memberArrayList = new MemberArrayList();
		
		Member Lee = new Member(101, "�̼���");
		Member Kim = new Member(102, "������");
		Member Gang = new Member(103, "������");
		
		memberArrayList.addMember(Lee);
		memberArrayList.addMember(Kim);
		memberArrayList.addMember(Gang);
		
		memberArrayList.showAll();
		System.out.println();
		
		memberArrayList.removeMember(Kim.getMemberId());
		memberArrayList.removeMember(104);
		System.out.println();
		
		memberArrayList.showAll();
	}

}
