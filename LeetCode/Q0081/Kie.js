
function exist_in_first(nums, start, element){
    return nums[start] <= element;
}

function should_go_next(nums, start, element){
    return nums[start] === element;
}

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {boolean}
 */
var search = function(nums, target) {
    if(nums.length === 0){
        return false;
    }
    let left = 0;
    let right = nums.length-1;

    while(left <= right){
        let mid = Math.floor((left + right) /2);
        if(nums[mid] === target){
            return true;
        }
        if(should_go_next(nums, left, nums[mid])){
            left++;
            continue;
        }
        let mid_at_first = exist_in_first(nums, left, nums[mid]);
        let target_at_first = exist_in_first(nums, left, target);
        if(mid_at_first !== target_at_first){
            if(mid_at_first){
                left = mid +1;
            }else{
                right = mid-1;
            }
        }else{
            if(nums[mid] < target){
                left = mid +1;
            }else{
                right = mid-1;
            }
        }
    }
    return false;
};

let nums = [1,0,1,1,1]
let target = 0
console.log(search(nums, target))