import java.util.HashMap;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int lenght = s.length();
        int result = 0;
        int candidate = 0;
        HashMap<Character, Integer> hash = new HashMap<>();
        for (int i = 0; i < lenght; i++) {
            if (hash.containsKey(s.charAt(i))) {
                candidate = hash.get(s.charAt(i)) > candidate ? hash.get(s.charAt(i)) : candidate;
            }
            result = (i - candidate + 1) > result ? (i - candidate + 1) : result;
            hash.put(s.charAt(i), i + 1);
        }
        return result;
    }
}

public class main {

    public static void main(String[] args) {
        var s = new Solution();
        System.out.println(s.lengthOfLongestSubstring("pwwkew"));
    }
}

