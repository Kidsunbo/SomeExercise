package kid.Question;

/**
 * Created by Administrator on 2016/9/20.
 */


/**
 *
 *  写个函数检查指定的元素是否出现在列表中。
 *
 */

public class Q14 {

    private static <T> boolean isIn(T[] list , T element){
        for(T i : list){
            if(element == i) {
                return true;
            }
        }
        return false;
    }


    public static void main(String[] args){


        /*
        Cause T can only represent reference type, so use Character instead of char.
         */
        Character ar[] = {'1','2','3','4','6'};

        System.out.println(isIn(ar, '1')); //auto boxing

        System.out.println(isIn(ar, '5')); //auto boxing

        /*
        Same as above
         */
        Integer br[] = {1,2,3,4,6};

        System.out.println(isIn(br,1));

        System.out.println(isIn(br,5));
    }


}
