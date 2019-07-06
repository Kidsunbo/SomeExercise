public class Kie {


    public static void main(String[] args) {
        Solution s = new Solution();
        int[][] matrix = new int[][]{
                {5, 1, 9, 11},
                {2, 4, 8, 10},
                {13, 3, 6, 7},
                {15, 14, 12, 16}
        };
//        int[][] matrix = new int[][]{
//                {1, 2, 3},
//                {4, 5, 6},
//                {7,8,9}
//        };

//        int[][] matrix = new int[][]{
//                {1,2},
//                {3,4}
//        };
        s.rotate(matrix);
        for(int i = 0;i<matrix.length;i++){
            for(int j=0;j<matrix[i].length;j++){
                System.out.printf("%d ",matrix[i][j]);
            }
            System.out.println();
        }
    }

}

class Solution {
    public void rotate(int[][] matrix) {
        int half = matrix.length/2;
        for(int i=0;i<half;i++){
            for(int j = i+1;j<matrix.length-i;j++) {
                int topleft = matrix[i][j];
                int topright=matrix[j][matrix.length-i-1];
                int botleft=matrix[matrix.length-1-j][i];
                int botright=matrix[matrix.length-i-1][matrix.length-1-j];

                matrix[i][j] = botleft;
                matrix[j][matrix.length-i-1]=topleft;
                matrix[matrix.length-1-j][i] = botright;
                matrix[matrix.length-i-1][matrix.length-1-j] = topright;
            }
        }
    }
}