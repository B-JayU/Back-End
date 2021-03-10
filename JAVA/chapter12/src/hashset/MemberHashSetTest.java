package hashset;

import collection.Member;

public class MemberHashSetTest {

	public static void main(String args[]) {
		MemberHashSet memberHashSet = new MemberHashSet();
		
		Member memberLee = new Member(102, "이순신");
		Member memberKim = new Member(101, "김유신");
		Member memberShin = new Member(103, "신사임당");
		
		memberHashSet.addMember(memberLee);
		memberHashSet.addMember(memberKim);
		memberHashSet.addMember(memberShin);
		
		memberHashSet.showAll();
	}

}
