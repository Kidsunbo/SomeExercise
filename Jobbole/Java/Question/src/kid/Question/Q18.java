package kid.Question;

/**
 * Created by Administrator on 2016/10/9.
 */

import java.util.Iterator;
import java.util.ListIterator;
import java.util.Vector;

/**
 * 写三个函数来计算列表中数字的和：分别用for循环，while循环和递归完成
 * (看来第16题我的确是理解错了)
 *
 *
 */


public class Q18 {




    //for loop
    private static <T extends Number> double sumWithForLoop(Vector<T> v){
        double sum = 0;
        for(Number i : v) {
            sum += i.doubleValue();
        }
        return sum;
    }


    //While
    private static <T extends Number> double sumWithWhile(Vector<T> v){
        double sum = 0;

        //Java的迭代器做的还是挺奇怪的，跟C++的很不一样，比如迭代器指向元素之间而不是指向元素→_→，用起来略不习惯。。。
        //还是用index表示比较习惯。。。
        ListIterator<T> beg = v.listIterator();
        while(beg.hasNext()){
            sum += beg.next().doubleValue();
        }
        return sum;
    }


    //Recursion
    private static <T extends Number> double sumWithRecursion(Vector<T> v){

        if(v.isEmpty()){
            return 0;
        }

        T temp = v.remove(0);
        return temp.doubleValue()+sumWithRecursion(v);


    }

    public static void main(String[] args){

        Vector<Integer> test = new Vector<>();
        for(int i = 0;i!=100;i++){
            test.add(i);
        }

        System.out.println("sumWithForLoop  "+sumWithForLoop(test));
        System.out.println("sumWithWhile   "+ sumWithWhile(test));
        System.out.println("sumWithRecursion   "+sumWithRecursion(test));

    }

}
