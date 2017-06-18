package kid.Question;

import java.math.BigInteger;

/**
 * Created by Administrator on 2016/9/4.
 */

/*
根据给定公式计算π
 */

public class Q11 {


    public static void main(String[] args){
        double result = 0;
        for(int k=1;k<=Math.pow(10,6);k++){
            result += Math.pow(-1, k + 1) / (2 * k - 1);
        }
        result *=4;
        System.out.println(result);
    }

}
