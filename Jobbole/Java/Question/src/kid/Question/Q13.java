package kid.Question;

import java.util.Vector;

/**
 * Created by Administrator on 2016/9/4.
 */

/*
写函数逆转列表，最好是原地逆转
 */
public class Q13 {

    public static void reverse(Vector<? extends Number> v){

        reverseHelper(v);

    }

    /**
     * 由于Capture ? extends Number指的是Number的子类们，也就是如Double、Integer等类型
     * 由于编译器无法确定?所代表的是什么类型，因此在操作过程中，只可以取出（get），不可以写入（set），
     * 因为编译器不知道容器是Vector<Integer>还是Vector<Double>或者是其他，所以无法把Integer的值传入Vector<Double>,
     * 也无法把Double的值传入Vector<Integer>。
     * 通过加入helper方法，可以让编译器通过泛型在编译期间的类型擦除，从而让T确定出Vector<? extends Number>的类型，
     * 并用T表示Capture ? extends Number所表示的类型，并在后续代码中对T类型的变量进行写入写出操作。
     *
     *
     * @param v 传入的Collector
     * @param <T> 用于消除wildcard的匹配问题
     */
    private static <T> void reverseHelper(Vector<T> v){
        for (int i = 0,j = v.size()-1; i <j ; i++,j--) {
            T temp = v.get(j);
            v.set(j,v.get(i));
            v.set(i,temp);
        }
    }


    public static void main(String[] args){
        Vector<Integer> v = new Vector<>();
        for (int i = 0; i <10 ; i++) {
            v.add(i);
        }
        System.out.println(v);
        reverse(v);
        System.out.println(v);

    }
}
