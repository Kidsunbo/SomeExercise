package kid.Question;

/**
 * Created by Administrator on 2016/9/4.
 */


/*
写个程序打印出接下来的20个闰年。
 */

public class Q10 {


    public static boolean isLeapYear(int year){
        if(year%4==0 && year%100 != 0){
            return true;
        }
        else if(year%100 == 0 && year%400 ==0){
            return  true;
        }
        else return false;

    }

    public static void main(String[] args){

        int currentYear = 1016;
        for(int i =0;i != 1000;i++,currentYear++){
            if(isLeapYear(currentYear)){
                System.out.println(currentYear);
            }
        }

    }

}
