import java.util.LinkedList;
// implement bst (binary search tree)
// insert delete findmin findmax printpreorder printpostorder printinorder printlevelorder

class Node {
    int data;
    Node left;
    Node right;
    Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class BST {
    Node root;
    BST() {
        root = null;
    }

    void insert(int data) {
        root = insert(root, data);
    }

    Node insert(Node root, int data) {
        if (root == null) {
            root = new Node(data);
            return root;
        }
        if (data < root.data) {
            root.left = insert(root.left, data);
        } else {
            root.right = insert(root.right, data);
        }
        return root;
    }

    void delete(int data) {
        root = delete(root, data);
    }

    Node delete(Node root, int data) {
        if (root == null) {
            return root;
        }
        if (data < root.data) {
            root.left = delete(root.left, data);
        } else if (data > root.data) {
            root.right = delete(root.right, data);
        } else {
            if (root.left == null) {
                return root.right;
            } else if (root.right == null) {
                return root.left;
            }
            root.data = findMin(root.right);
            root.right = delete(root.right, root.data);
        }
        return root;
    }
    
        int findMin(Node root) {
            int min = root.data;
            while (root.left != null) {
                min = root.left.data;
                root = root.left;
            }
            return min;
        }
    
        int findMax(Node root) {
            int max = root.data;
            while (root.right != null) {
                max = root.right.data;
                root = root.right;
            }
            return max;
        }
    
        void printPreOrder() {
            printPreOrder(root);
        }
    
        void printPreOrder(Node root) {
            if (root == null) {
                return;
            }
            System.out.print(root.data + " ");
            printPreOrder(root.left);
            printPreOrder(root.right);
        }
    
        void printInOrder() {
            printInOrder(root);
        }
    
        void printInOrder(Node root) {
            if (root == null) {
                return;
            }
            printInOrder(root.left);
            System.out.print(root.data + " ");
            printInOrder(root.right);
        }
    
        void printPostOrder() {
            printPostOrder(root);
        }
    
        void printPostOrder(Node root) {
            if (root == null) {
                return;
            }
            printPostOrder(root.left);
            printPostOrder(root.right);
            System.out.print(root.data + " ");
        }
        
        void printLevelOrder() {
            LinkedList<Node> queue = new LinkedList<>();
            queue.add(root);
            while (!queue.isEmpty()) {
                Node temp = queue.poll();
                System.out.print(temp.data + " ");
                if (temp.left != null) {
                    queue.add(temp.left);
                }
                if (temp.right != null) {
                    queue.add(temp.right);
                }
            }
        }
}

public class ImplementBinarySearchTree {
    public static void main(String[] args) {
        BST bst = new BST();
        bst.insert(5);
        bst.insert(3);
        bst.insert(7);
        bst.insert(2);
        bst.insert(4);
        bst.insert(6);
        bst.insert(8);
        bst.printPreOrder();
        System.out.println();
        bst.printInOrder();
        System.out.println();
        bst.printPostOrder();
        System.out.println();
        bst.printLevelOrder();
        System.out.println();
        bst.delete(3);
        bst.printPreOrder();
        System.out.println();
        bst.delete(5);
        bst.printPreOrder();
        System.out.println();
        bst.delete(7);
        bst.printPreOrder();
        System.out.println();
    }
}
