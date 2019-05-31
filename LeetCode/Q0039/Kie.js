/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    if(nums.length===0) return [-1,-1];
    if(nums.length===1) return nums[0]===target?[0,0]:[-1,-1];
    let beg = 0;
    let end = nums.length-1;
    let mid;

    while(beg<=end){
        mid = Math.floor((beg+end)/2);
        if(nums[mid]>target) end = mid-1;
        else if(nums[mid]<target) beg = mid+1;
        else break;
    }

    if(beg>end) return [-1,-1];
    //Determine beg
    let beg_temp = mid;
    while(nums[--beg_temp]===target);
    beg = beg_temp+1;
    //Determine end
    let end_temp = mid;
    while(nums[++end_temp]===target);
    end = end_temp-1;
    return [beg,end];

};

window.onload=function () {
    $("#param").keyup(function () {
        let values = $("#param").val().split(",").map(x=>parseInt(x));
        if(values[1]&&values[1]!=="") {
            $("#output").text(searchRange(values.slice(0,values.length-1),values[values.length-1]));
        }

    })
};