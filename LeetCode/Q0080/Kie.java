public class Kie {

    public static void main(String[] args) {
        var s = new Solution();
        System.out.println(s.removeDuplicates(new int[]{1,1,1,1,2,3,4,4,5,5,6}));
    }
}


class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length < 3) return nums.length;

        var index = 2;
        for(var i = 2; i< nums.length; i++){
            if(nums[i] != nums[index-2]){
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
}
