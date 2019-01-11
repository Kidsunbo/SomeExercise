public class Kie {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.myAtoi("-6147483648"));
    }

}

class Solution {
    public int myAtoi(String str) {
        final int MAX = 2147483647;
        final int MIN = -2147483648;
        if(str==null || str.trim().equals("")) return 0;
        str = str.trim();

        int index = 0;

        int sign = 1;
        if(str.charAt(index)=='-') {
            sign = -1;
            index++;
        }
        else if(str.charAt(index)=='+') index++;

        int digitCount = 0;
        for(;index<str.length() && str.charAt(index)=='0';index++);

        int sum = 0;
        for(;index<str.length();index++){
            int distance = str.charAt(index)-'0';
            if(distance>-1 && distance<10){
                digitCount++;
                if(digitCount== 10 && sign==1 &&(sum>MAX/10 || sum == MAX/10 && distance>7) || sign==1&&digitCount>10) return MAX;
                if(digitCount== 10 && sign==-1 &&(sum*sign<MIN/10 || sum*sign == MIN/10 && distance>8) || sign==-1&&digitCount>10) return MIN;
                sum=(sum*10+distance);
            }
            else break;
        }
        return sum*sign;
    }
}