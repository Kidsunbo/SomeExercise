package kid.Question;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Vector;

/**
 * Created by Administrator on 2016/9/4.
 */

/*
1. 写一个函数，返回列表中最大的数
 */

public class Q12 {


    public static Double getMax(ArrayList<? extends Number> l) {
        Iterator<? extends Number> it = l.iterator();
        double result;
        if (it.hasNext()) {
            result = (Double) it.next();

            while(it.hasNext()){
                result = Math.max(result, (Double) it.next());
            }
            return result;
        }
        else return null;
    }

    public static void main(String[] args){

        ArrayList<Double> l = new ArrayList<>();
        for (int i = 0; i <10000 ; i++) {
            double num = Math.random()*1000000;
            l.add(num);
        }

        System.out.println(Q12.getMax(l));


    }

}
