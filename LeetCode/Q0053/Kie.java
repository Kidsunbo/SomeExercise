public class Kie {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.maxSubArray(new int[]{-2,1,-3,4,-1,2,1,-5,4}));
    }

}

class Solution {
    public int maxSubArray(int[] nums) {
        if(nums.length==0) return 0;
        int max = nums[0];
        int temp_max=0;

        for(int i : nums){
            temp_max+=i;
            max= Math.max(max, temp_max);
            if(temp_max<0) temp_max=0;
        }
        return max;
    }
}
