

class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix.length==0) return false;
        if(matrix[0].length==0) return false;
        // Return if target is not in the matrix
        if(matrix[0][0]>target) return false;
        if(matrix[matrix.length-1][matrix[matrix.length-1].length-1]<target) return false;

        int[] arr = new int[1];
        boolean found = binarySearch(matrix,target,arr);
        if(found) return true;
        return binarySearch(matrix[arr[0]],target);
    }

    // If return true, means the target is in the first value. else return false
    public boolean binarySearch(int[][] matrix,int target,int[] arr){
        // Find the closest array whose first value is less than target
        int start = 0;
        int end = matrix.length-1;
        while(start<end){
            int mid = (start+end)/2;
            if(matrix[mid][0]==target)return true;
            else if(matrix[mid][0]<target) {
                start = mid + 1;
                if(matrix[start][0]>target){
                    arr[0] = start-1;
                    return false;
                }
            }
            else if(matrix[mid][0]>target) {
                end = mid - 1;
                if (matrix[end][0] < target) {
                    arr[0] = end;
                    return false;
                }
            }
        }
        arr[0] = start;
        return false;
    }

    public boolean binarySearch(int[] matrix,int target){
        // Find if the value is in the array
        int start = 0;
        int end = matrix.length-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(matrix[mid]==target) return true;
            else if(matrix[mid]<target) start=mid+1;
            else if(matrix[mid]>target) end = mid-1;
        }
        return false;
    }

}


public class Kie {
    public static void main(String[] args) {
        var s = new Solution();
        int[][] matrix = {
                {1, 3, 5, 7},
                {10, 11, 16, 20},
                {23, 30, 34, 50}
        };
        for(int i = 0;i<52;i++){
            if(s.searchMatrix(matrix,i)){
                System.out.print(i+",");
            }
        }


    }
}