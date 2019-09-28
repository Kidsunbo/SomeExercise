public class Kie {

    public static void main(String[] args) {
        var s = new Solution();
        System.out.println(s.uniquePathsWithObstacles(
                new int[][]{
                        {1,0,0},
                }
        ));
    }
}

// Time 100%  Memory 83.08%
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if(obstacleGrid.length==0 || obstacleGrid[0].length==0) return 0;
        int m=obstacleGrid[0].length;
        int n=obstacleGrid.length;
        int[][] mat = new int[n][m];
        boolean dieX=false;
        boolean dieY=false;
        //Change the value of the first column and row
        for(int i=0;i<m;i++){
            if(dieX||obstacleGrid[0][i]==1) dieX=true;
            else mat[0][i]=1;
        }
        for(int i=0;i<n;i++){
            if(dieY||obstacleGrid[i][0]==1) dieY=true;
            else mat[i][0]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[j][i]==1) continue;
                mat[j][i]=mat[j-1][i]+mat[j][i-1];
            }
        }
        return mat[n-1][m-1];
    }
}