public class Kie {

    public static void main(String[] args) {
        var s = new Solution();
        System.out.println(s.romanToInt("MCMXCIV"));
    }
}

class Solution {
    public int romanToInt(String s) {
        int result = 0;
        for(int i = 0;i<s.length();i++){
            if(s.charAt(i)=='I'){
                if(i+1<s.length() && s.charAt(i+1)=='V') {result+=4;i++;}
                else if(i+1<s.length() && s.charAt(i+1)=='X') {result+=9;i++;}
                else result+=1;
            }
            else if(s.charAt(i)=='X'){
                if(i+1<s.length() && s.charAt(i+1)=='L') {result+=40;i++;}
                else if(i+1<s.length() && s.charAt(i+1)=='C') {result+=90;i++;}
                else result+=10;
            }
            else if(s.charAt(i)=='C'){
                if(i+1<s.length() && s.charAt(i+1)=='D') {result+=400;i++;}
                else if(i+1<s.length() && s.charAt(i+1)=='M') {result+=900;i++;}
                else result+=100;
            }
            else if(s.charAt(i)=='V') result+=5;
            else if(s.charAt(i)=='L') result+=50;
            else if(s.charAt(i)=='D') result+=500;
            else if(s.charAt(i)=='M') result+=1000;
        }
        return result;
    }
}