/*************************************************************************
	> File Name: 297-二叉树的序列化和反序列化.c
	> Author: 
	> Mail: 
	> Created Time: 四  9/ 6 16:54:53 2018
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {
 
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root==null) return "[]";
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        sb.append(root.val);
        sb.append(",");
        sb.append(serialize(root.left));
        sb.append(",");
        sb.append(serialize(root.right));
        sb.append("]");
        // System.out.printf("serialize: %s\n", sb.toString());
        return sb.toString();
    }
 
    private int pos;
    private TreeNode parse(String data) {
        if (data.charAt(pos) != '[') return null;
        pos ++;
        if (data.charAt(pos) == ']') {
            pos ++;
            return null;
        }
        int val = 0;
        boolean negative = false;
        if (data.charAt(pos) == '-') {
            negative = true;
            pos ++;
        }
        for(;pos<data.length() && data.charAt(pos)>='0' && data.charAt(pos)<='9'; pos ++) {
            val = val*10+data.charAt(pos)-'0';
        }
        if (negative) val = -val;
        TreeNode node = new TreeNode(val);
        // System.out.printf("val=%d\n", val);
        if (data.charAt(pos) != ',') return null;
        pos ++;
        node.left = parse(data);
        if (data.charAt(pos) != ',') return null;
        pos ++;
        node.right = parse(data);
        if (data.charAt(pos) != ']') return null;
        pos ++;
        return node;
    } 
    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        pos = 0;
        return parse(data);
    }
}

