

class Solution {
    public int strStr(String haystack, String needle) {
        // Tricky
        //return haystack.indexOf(needle);


        if(needle.length()==0) return 0;
        for(int index= 0;index<haystack.length();index++){
            if(haystack.charAt(index)!=needle.charAt(0)) continue;
            if(haystack.length()-index<needle.length()) break;
            boolean flag =true;
            for(int i =1;i<needle.length();i++){
                if(haystack.charAt(index+i)!=needle.charAt(i)){
                    flag = false;
                    break;
                }
            }
            if(flag) return index;
        }
        return -1;


    }
}


public class Kie {

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.strStr("hello","l0l"));
    }
}


