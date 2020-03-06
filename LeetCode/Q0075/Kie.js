
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
    let [zero,one,two] = [0,0,nums.length-1];
    while(one<=two){
        // Move one until
        if(nums[one]===1){
            one++;
        }
        else if(nums[one]===0){
            [nums[zero],nums[one]] = [nums[one],nums[zero]];
            while(nums[++zero]===0);
            one=zero;
        }
        else if(nums[one]===2){
            [nums[two],nums[one]] = [nums[one],nums[two]];
            while(nums[--two]===2);
        }
    }
};

window.onload=function () {

    $("#param").keyup(function () {
        try {
            let values = eval($("#param").val());
            if (values.length >= 1) {
                another(values);
                $("#output").html(values);
            }
        }
        catch (e) {}
    })
};