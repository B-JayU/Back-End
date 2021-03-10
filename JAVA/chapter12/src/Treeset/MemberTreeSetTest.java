package Treeset;

import collection.Member;

public class MemberTreeSetTest {
	
	public static void main(String args[]) {
		MemberTreeSet memberTreeSet = new MemberTreeSet();
		
		Member memberLee = new Member(102, "이순신");
		Member memberKim = new Member(101, "김유신");
		Member memberShin = new Member(103, "신사임당");
		
		memberTreeSet.addMember(memberLee);
		memberTreeSet.addMember(memberKim);
		memberTreeSet.addMember(memberShin);
		
		memberTreeSet.showAll();
	}
}
