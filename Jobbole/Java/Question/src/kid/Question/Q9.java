package kid.Question;
import java.util.Random;
import java.util.Scanner;

import static java.lang.System.out;
/**
 * Created by Administrator on 2016/8/29.
 */


/*
 *
  9. 写一个竞猜游戏，用户必须猜一个秘密的数字，在每次猜完后程序会告诉用户他猜的数是太大了还是太小了，
  直到猜测正确，最后打印出猜测的次数。如果用户连续猜测同一个数字则只算一次。
 *
 */
public class Q9 {

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        Random r = new Random();
        int resultNum = r.nextInt(100); //100以内的数字
        Integer times = 1;                //只是为了玩一下Integer
        Integer num = input.nextInt();
        Integer last = 101;

        while(!num.equals(resultNum)){
            if(num > resultNum){
                out.println("大了");
            }
            if(num<resultNum){
                out.println("小了");
            }
            times++;
            if(last.equals(num)){
                times--;
            }
            last = num;
            num = input.nextInt();

        }

        out.printf("True number is %d, you have used %d times to guess it out",resultNum,times);
    }

}
