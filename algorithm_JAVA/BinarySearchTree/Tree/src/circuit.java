public class circuit {

	static Node[] queue = new Node[30];
	static int front=0, rear =0;
	
	static void inorder_tree_walk(Node r) {
		if (r != null) {
			inorder_tree_walk(r.getLeft());
			System.out.print(r.getData() + " ");
			inorder_tree_walk(r.getRight());
		}
	}
	
	static void preorder_tree_walk(Node r) {
		if (r != null) {
			System.out.print(r.getData() + " ");
			preorder_tree_walk(r.getLeft());
			preorder_tree_walk(r.getRight());
		}
	}
	
	static void postorder_tree_walk(Node r) {
		if (r != null) {
			postorder_tree_walk(r.getLeft());
			postorder_tree_walk(r.getRight());
			System.out.print(r.getData() + " ");
		}
	}
	
	//level order
	static void level_order_tree_traversal(Node r) {
		
		queue[rear++] = r;	
		while(front<=rear) {
			Node v = queue[front++];
			queue[rear++] = v.getLeft();
			queue[rear++] = v.getRight();
		}
	}
	
	

}
