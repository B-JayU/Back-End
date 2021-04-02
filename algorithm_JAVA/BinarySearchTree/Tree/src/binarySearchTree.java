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
		
		
		
		// ��ȸ ���
		System.out.println("inorder ��ȸ���");
		circuit.inorder_tree_walk(root);
		System.out.println();
		System.out.println("preorder ��ȸ���");
		circuit.preorder_tree_walk(root);
		System.out.println();
		System.out.println("postorder ��ȸ���");
		circuit.postorder_tree_walk(root);
		System.out.println();
		
		// Ž�� ���
		Node search_node;
		System.out.print("\n\nã���� �ϴ� ���� �Է��ϼ��� :");
		Scanner sc = new Scanner(System.in);
		int search = sc.nextInt();
		search_node = Operation.search(root, search);
		
		// �������
		Node delete_node;
		System.out.print("\n\n�����ϰ��� �ϴ� ���� �Է��ϼ��� : ");
		int del = sc.nextInt();
		root = Operation.delete(root, del);
		
		// ��ȸ ���
		System.out.println("inorder ��ȸ���");
		circuit.inorder_tree_walk(root);
		System.out.println();
		System.out.println("preorder ��ȸ���");
		circuit.preorder_tree_walk(root);
		System.out.println();
		System.out.println("postorder ��ȸ���");
		circuit.postorder_tree_walk(root);
		System.out.println();
		
		
	}
	

}
