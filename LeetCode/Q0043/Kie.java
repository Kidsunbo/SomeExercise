import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Kie {

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.multiply("0","0"));

    }
}

class Solution {
    public String multiply(String num1, String num2) {
        if(num1.length()==0 || num2.length()==0) return "";
        ArrayList<Integer> temp = new ArrayList<>(219); // Maximum numbers of number is 219
        for(int i =0;i<219;i++){
            temp.add(0);
        }
        for(int i = num1.length()-1;i>=0;i--){
            int dig1 = num1.charAt(i)-'0';
            for(int j = num2.length()-1;j>=0;j--){
                int dig2 = num2.charAt(j)-'0';
                temp.set(temp.size()-1-(num1.length()-1-i)-(num2.length()-1-j),temp.get(temp.size()-1-(num1.length()-1-i)-(num2.length()-1-j))+dig1*dig2);
            }
        }

        int beg = -1;
        for(int i = temp.size()-1;i>0;i--){
            temp.set(i-1,(temp.get(i)/10+temp.get(i-1)));
            temp.set(i,temp.get(i)%10);
            if(temp.get(i)!=0) beg=i;
        }
        if(beg==-1) return "0";
        StringBuilder sb = new StringBuilder();
        for(int i = beg;i<temp.size();i++){
            sb.append(temp.get(i));
        }
        return sb.toString();
    }
}
