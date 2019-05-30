class Solution {
    public String countAndSay(int n) {
        String result = "1";
        for(int ind = 1;ind<n;ind++){
            char pre = result.charAt(0);
            int count = 1;
            StringBuilder str = new StringBuilder();
            for(int i = 1;i<result.length();i++){
                if(result.charAt(i)==pre){
                    count++;
                }
                else{
                    str.append(count);
                    str.append(pre);
                    count=1;
                    pre=result.charAt(i);
                }
            }
            str.append(count);
            str.append(pre);
            result=str.toString();
        }
        return result;
    }
}

public class Kie {

    public static void main(String[] args) {
        var s = new Solution();
        System.out.println(s.countAndSay(5));
    }
}
