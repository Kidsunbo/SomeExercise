/**
 * Created by bxs863 on 26/08/19.
 */
public class Kie {

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.lengthOfLastWord("hello"));
    }


}

class Solution {
    public int lengthOfLastWord(String s) {
        s=s.trim();
        if(s.length()==0) return 0;
        if(s.lastIndexOf(' ')==-1) return s.length();
        return s.substring(s.lastIndexOf(' ')+1).length();
    }
}
