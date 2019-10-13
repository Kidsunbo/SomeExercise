import java.util.ArrayList;
import java.util.List;

// Time 43.08%  Memory 97.22%
class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        ArrayList<String> result = new ArrayList<>();
        ArrayList<String> current = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        int i = 0;
        int charactorCount = 0;

        while(i<words.length){
            if(charactorCount+words[i].length()>maxWidth){
                ArrayList<String> spaces = getSpaces(current.size()-1,maxWidth-charactorCount+1);
                for(int si =0;si<spaces.size();si++){
                    sb.append(current.get(si));
                    sb.append(spaces.get(si));
                }
                sb.append(current.get(current.size()-1));
                if(spaces.isEmpty()){
                    for(int si = 0;si<maxWidth-current.get(current.size()-1).length();si++){
                        sb.append(" ");
                    }
                }
                result.add(sb.toString());
                sb.delete(0,sb.length());
                current.clear();
                charactorCount=0;// Update charactorCount

            }
            current.add(words[i]);
            charactorCount+=words[i].length()+1;
            i++;
        }
        // Last line
        for(int si=0;si<current.size()-1;si++){
            sb.append(current.get(si));
            sb.append(" ");
        }
        sb.append(current.get(current.size()-1));
        for(int si = 0;si<maxWidth-charactorCount+1;si++){
            sb.append(" ");
        }
        result.add(sb.toString());

        return result;
    }

    public static ArrayList<String> getSpaces(int groupNum,int spaceNum){
        if(groupNum==0) return new ArrayList<>();
        ArrayList<String> arrayList = new ArrayList<>(groupNum);
        int reminder = spaceNum%groupNum;
        int quotient = spaceNum/groupNum+1;
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<quotient;i++){
            sb.append(" ");
        }
        String space = sb.toString();
        for(int i=0;i<groupNum;i++){
            if(i<reminder) arrayList.add(space+" ");
            else arrayList.add(space);
        }
        return arrayList;
    }
}

public class Kie {
    public static void main(String[] args) {
        Solution s = new Solution();
        String[] words = new String[]{"ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"};
        int maxWidth = 16;
        for(String line:s.fullJustify(words,maxWidth)){
            System.out.println(line);
        }



    }


}
