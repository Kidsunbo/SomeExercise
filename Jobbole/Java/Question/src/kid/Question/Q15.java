package kid.Question;

/**
 * Created by Administrator on 2016/9/21.
 */


import java.util.ArrayList;

/**
 *
 * 写个函数返回列表中奇数位置的所有元素。(题目有bug，第一位是0还是1，如果是0，那么第一位是偶数位，第一位是1，那么是奇数为）
 *
 */
public class Q15 {


    private static <T> ArrayList<T> getOddPosElement(T[] list){
        ArrayList<T> temp = new ArrayList<>();

        for(int i =0;i<list.length;i+=2){
            temp.add(list[i]);
        }

        return temp;

    }

    public static void main(String[] args){

        Integer[] o = {1,2,3,4,5,6,6,7,8,8,9,10,11,12,13,14,15,16};// Create a array of integer
        ArrayList<Integer> result; // Declare a reference of an ArrayList
        result = Q15.getOddPosElement(o); // Get the result
        System.out.println(result); //print


        // Test for Character
        Character[] c = {'h', 'e', 'l', 'l', 'o', ' ','w','o','r','l','d'};
        ArrayList<Character> resultForC;
        resultForC = Q15.getOddPosElement(c);
        System.out.println(resultForC);

    }


}
