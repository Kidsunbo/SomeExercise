/**
 * Created by Administrator on 2016/8/29.
 */
package kid.Question;

/*
7. 写程序打印出12×12乘法表。
 */

import static java.lang.System.out;

public class Q7 {

    public static void main(String[] args){

        for(int col = 1;col!=10;col++){

            for(int raw = 1;raw<=col;raw++){
                out.printf("%2d×%d=%2d ",raw,col,col*raw);

            }
            out.println();

        }


    }


}
