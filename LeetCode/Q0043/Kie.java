public class Kie {

    public static void main(String[] args) {
        var s = new Solution();
        //System.out.println(s.multiply("",""));
        System.out.println(s.add("123","123"));
    }
}

class Solution {
    public String multiply(String num1, String num2) {
        return null;
    }

    String add(String num1,String num2){
        int carry=0;
        StringBuilder sb=new StringBuilder();
        int length=num1.length()>num2.length()?num1.length(): num2.length();
        String n1=num1.length()>num2.length()?num1: num2;
        String n2 = num1.length()<num2.length()?num1: num2;
        n2="0".repeat(length-n2.length())+n2;
        for(int i = length-1;i>=0;i-=7){
            if(i>=7){
                int temp =Integer.valueOf(n1.substring(i-7,i+1))+Integer.valueOf(n2.substring(i-7,i+1))+carry;
                sb.append(temp%10000000);
                carry=temp/10000000;
            }
            else{
                int temp =Integer.valueOf(n1.substring(0,i+1))+Integer.valueOf(n2.substring(0,i+1))+carry;
                sb.append(temp%10000000);
                carry=temp/10000000;
            }
        }
        return sb.toString();
    }
}
