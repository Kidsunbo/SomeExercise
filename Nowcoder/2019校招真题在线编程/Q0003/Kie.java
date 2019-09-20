import java.util.*;

public class Kie {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int numberOfExample = input.nextInt();
        input.nextLine();
        ArrayList<String> roads = new ArrayList<>(numberOfExample);
        for(int i=0;i<numberOfExample;i++){
            input.nextLine();
            roads.add(input.nextLine());
        }
        for(String road : roads){
            System.out.println(calculate(road));
        }
    }

    public static int calculate(String road){
        if(road.length()<=3) return road.contains(".")?1:0;
        int i = 0;
        int num = 0;
        ArrayList<Character> arr = new ArrayList<>();
        while(i<road.length()){
            char temp = road.charAt(i);
            i++;
            if(arr.isEmpty()&&temp=='X') continue;
            else if(arr.size()==3){
                if(temp=='.') {
                    i--;
                }
                arr.clear();
                num++;
            }else{
                arr.add(temp);
            }
        }
        if(arr.contains('.')) num++;
        return num;
    }

}
