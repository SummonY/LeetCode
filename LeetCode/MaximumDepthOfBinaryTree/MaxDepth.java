package Summon;

import java.io.IOException;
import java.util.Scanner;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) {
		val = x;
	}
}

public class MaxDepth {
	
	public static TreeNode createTree() throws IOException {
		TreeNode T;
		int val;
		Scanner cin = new Scanner(System.in);
		val = cin.nextInt();
		if (val != -1) {
			T = new TreeNode(val);
			T.left = createTree();
			T.right = createTree();
		} else {
			T = null;
		}
		return T;
	}
	
	public static int maxDepth(TreeNode root) {
		if (root == null)
			return 0;
		int l, r;
		l = maxDepth(root.left);
		r = maxDepth(root.right);
		return (l > r) ? (l + 1) : (r + 1);
	}
	
	
	public static void main(String[] argc) throws IOException {
		TreeNode T;
		T = createTree();
		System.out.println("Maximum Depth : " + maxDepth(T));
	}
}
