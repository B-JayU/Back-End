
public class Operation {

	// 삽입 연산
	static public Node insert(Node r, Node n) {
		
		if (r == null) {
			r = n;
			return r;
		}
		
		if (r.getData() > n.getData()) {
			if (r.getLeft() != null) {
				insert(r.getLeft(), n);
			}else {
				r.setLeft(n);
			}
		}else {
			if(r.getRight() != null) {
				insert(r.getRight(), n);
			}else {
				r.setRight(n);
			}
		}
		
		return r;
	}
	
	//삭제 연산
	static public Node delete(Node r, int n) {
		
		Node temp = search(r, n);
		if (temp== null)
			return r;
		
		if (temp.getLeft() == null || temp.getRight() == null) {
			if (temp.getLeft() == null) {
				temp=temp.getRight();
			}else {;
				temp=temp.getLeft();
			}
		}else {
			
			Node successor = temp.getRight();
			Node pre=null;
			while(successor.getLeft() != null) {
				pre = successor;
				successor = successor.getLeft();
			}
			
			temp.setData(successor.getData());
			System.out.println("값 : " + n +  "노드가 삭제되었습니다.");
			pre.setLeft(null);
		}
		
		return r;
	}
		
	//탐색 연산
	static public Node search(Node r, int n) {
		
		if (r == null) {
			System.out.println("값을 찾을 수 없습니다.");
			return null;
		}
		
		if (r.getData() > n) {
			r = search(r.getLeft(), n);
		}else if(r.getData() < n){
			r = search(r.getRight(), n);
		}else {
			System.out.println("값이 존재합니다.");
			return r;
		}
		
		return r;
	}
	
	static public Node successor(Node r, int n) {
		
		if (r == null)
			return null;
		else {
			while(r.getLeft() != null) {
				r=r.getLeft();
			}
			return r;
		}
	}
}