import java.util.Arrays;

class Solution {
    public int search(int[] nums, int target) {
        if(nums.length==0) return -1;
        if(nums.length==1) return nums[0]==target?0:-1;
        if(nums[0]<nums[nums.length-1]){
            int i = Arrays.binarySearch(nums,target);
            return i>=0?i:-1;
        }
        else {
            int i = find_min(nums);
            int end = nums.length - 1;
            int beg = 0;
            if (target <= nums[nums.length - 1]) {
                beg = i;
            }
            if (target >= nums[0]) {
                end = i - 1;
            }

            while (end >= beg) {
                int mid = (beg + end) / 2;
                if (nums[mid] < target) beg = mid + 1;
                else if (nums[mid] > target) end = mid - 1;
                else return mid;
            }
            return -1;
        }
    }

    /**
     * Find the smallest value in O(logN)
     * @param nums
     * @return
     */
    public int find_min(int[] nums){
        int beg = 0;
        int end = nums.length-1;
        while(end-beg>1){
            int mid = (beg+end)/2;
            if(nums[mid]<nums[end]) end=mid;
            if(nums[mid]>nums[beg]) beg=mid;
        }
        return end;
    }
}

public class Kie {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.search(new int[]{1,2,3},4));
    }

}
