import java.util.Scanner;
public class binarySearchTree {
	
	static Node root = null;
	static int[] array = {13, 7, 20, 6, 9, 18, 23, 1, 8, 11, 22, 27};
	
	
	public static void main(String args[]) {
		
		Node temp;
		for (int i = 0; i < array.length; i++) {
			temp = new Node(array[i]);
			root = Operation.insert(root, temp);
		}
		
		
		
		// 순회 기능
		System.out.println("inorder 순회방식");
		circuit.inorder_tree_walk(root);
		System.out.println();
		System.out.println("preorder 순회방식");
		circuit.preorder_tree_walk(root);
		System.out.println();
		System.out.println("postorder 순회방식");
		circuit.postorder_tree_walk(root);
		System.out.println();
		
		// 탐색 기능
		Node search_node;
		System.out.print("\n\n찾고자 하는 값을 입력하세요 :");
		Scanner sc = new Scanner(System.in);
		int search = sc.nextInt();
		search_node = Operation.search(root, search);
		
		// 삭제기능
		Node delete_node;
		System.out.print("\n\n삭제하고자 하는 값을 입력하세요 : ");
		int del = sc.nextInt();
		root = Operation.delete(root, del);
		
		// 순회 기능
		System.out.println("inorder 순회방식");
		circuit.inorder_tree_walk(root);
		System.out.println();
		System.out.println("preorder 순회방식");
		circuit.preorder_tree_walk(root);
		System.out.println();
		System.out.println("postorder 순회방식");
		circuit.postorder_tree_walk(root);
		System.out.println();
		
		
	}
	

}
