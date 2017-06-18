package kid.Question;

/**
 * Created by Administrator on 2016/8/29.
 */
import java.util.*;

import static java.lang.System.out;
/*
8. 写程序打印所有的素数。（注意：如果你用的编程语言不支持任意大小的数，那么打印出所有你能表示的素数，包括最大数）
 */


// 不是最优算法，我只是想试试Collection怎么用。PS：程序没跑完。。。我可等不到结果出来。
public class Q8 {

    private static Queue<Integer> s = new LinkedList<>();

    public static void main(String[] args){
        int count = 0;
        for (int i = 1; i < Integer.MAX_VALUE; i++) {
            if (isPrime(i)) {
                s.add(i);

            }
        }


        while(!s.isEmpty()){
            out.printf("%d ",s.poll());
            count++;
            if(count == 10){
                out.println();
                count = 0;
            }
        }
    }

    public static boolean isPrime(int num){
        for(int i=2;i!=num;i++){
            if(num%i==0) {
                return false;
            }
        }
        return true;
    }
}
