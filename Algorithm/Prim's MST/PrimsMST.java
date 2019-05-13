public class PrimsMST {

    static int find_min(int[] v){
        int min = Integer.MAX_VALUE;
        int index = 0;
        for(int i = 0;i<v.length;i++){
            if(min>v[i]){
                min = v[i];
                index=i;
            }
        }
        return index;
    }


    static void primsMST(int[][] graph,int[] parents,int[] dis){
        boolean[] included = new boolean[graph.length]; // Create an array to store if the node has been visited
        for(int i =0;i<dis.length;i++){
            int m = find_min(graph[i]);
            included[m] = true;

            for(int j = 0;j<dis.length;j++){
                if(graph[m][j]!=0&&!included[j]&&dis[j]>graph[m][j]){
                    dis[j]=graph[m][j];
                    parents[j]=m;
                }
            }

        }


    }

    public static void main(String[] args) {
        int[][] graph = {
                {0, 2, 0, 6, 0},
                {2, 0, 3, 8, 5},
                {0, 3, 0, 0, 7},
                {6, 8, 0, 0, 9},
                {0, 5, 7, 9, 0}
        };
        int[] parents = new int[graph.length];
        int[] dis = new int[graph.length];
        for(int i = 0;i<graph.length;i++){
            parents[i]=-1;
            dis[i]=Integer.MAX_VALUE;
        }
        dis[0] = 0;
        primsMST(graph,parents,dis);

        for(int i:parents){
            System.out.println(i);
        }
        for(int i : dis){
            System.out.println(i);
        }

    }

}
