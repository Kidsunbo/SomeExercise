/**
 * Created by bxs863 on 22/01/19.
 */
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

public class Kie {


    public static void main(String[] args) {
        Solution s = new Solution();
        s.fourSum(new int[]{1, 0, -1, 0, -2, 2},0);
    }


}

class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        if(nums.length<4) return new ArrayList<>();
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        for(int first = 0;first<nums.length-3;first++){
            if(first>0 && nums[first]==nums[first-1]) continue;
            for(int second = first+1; second < nums.length-2;second++){
                if(second>first+1&&nums[second]==nums[second-1]) continue;
                int third = second+1;
                int forth = nums.length-1;
                while(third<forth){
                    if(third>second+1 && nums[third]==nums[third-1]){
                        third++;
                        continue;
                    }
                    int sum = nums[first]+nums[second]+nums[third]+nums[forth];
                    if(sum==target){
                        result.add(Arrays.asList(nums[first],nums[second],nums[third],nums[forth]));
                        third++;
                        forth--;
                    }
                    else if(sum>target) forth--;
                    else third++;
                }
            }

        }
        return result;
    }
}