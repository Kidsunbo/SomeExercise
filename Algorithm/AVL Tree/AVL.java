public class AVL {
    static class Node{
        public int value;
        public Node left = null;
        public Node right = null;
        public int height = 0;
        public Node(int value){this.value = value;}
    }

    private Node root = null;

    public AVL(){}

    public AVL(int value){
        root = new Node(value);
    }

    public void insert(int value){
        if(root == null) root = new Node(value);


    }

    public void remove(int value){
        if(root == null) return;
    }






    public static void main(String[] args) {
        AVL tree = new AVL();
    }
}
