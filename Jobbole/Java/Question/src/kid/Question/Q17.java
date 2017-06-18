package kid.Question;

/**
 * Created by Administrator on 2016/10/9.
 */


/**
 *
 * 写个函数测试一个字符串是否是回文。
 *
 */
public class Q17 {


    private static boolean isPlalindrome(String s){
        //类似于C++中迭代器的效果
        int beg = 0;
        int end = s.length()-1;
        while(beg < end){
            if(s.charAt(beg) != s.charAt(end)){
                return false;
            }
            beg++;
            end--;
        }
        return true;

    }


    public static void main(String[] args){
        String yes = "Hell o lleH";
        String no = "Hello world";
        System.out.println(yes+"   "+isPlalindrome(yes));
        System.out.println(no+"   "+isPlalindrome(no));

    }


}
