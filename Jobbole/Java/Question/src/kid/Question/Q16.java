package kid.Question;
/**
 * Created by Administrator on 2016/10/9.
 */


import java.util.Vector;

/**
 * 写个函数计算列表的运行花费总和（the running total）
 * （这个题目没看懂）
 *
 *
 */


public class Q16 {


    public static void main(String[] args){

        Vector<Integer> vec = new Vector<>();
        for(Integer i = 0;i!=10000;i++){
            vec.add(i);
        }

        long start = System.currentTimeMillis();
        long sum = 0;
        for(int i : vec){
            sum += i;
        }
        long end = System.currentTimeMillis();
        System.out.println("使用的时间是："+(end-start)+"毫秒");
        System.out.println("顺便说一下，和是："+sum);

    }







}
