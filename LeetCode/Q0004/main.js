function main() {
    $(document).ready(function () {
        let nums1 = [2,3,4,5];
        let nums2 = [];
        $("#output").text(findMedianSortedArrays(nums1,nums2).toString());
    })
}

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    let index1 = 0;
    let index2 = 0;
    let isIndex1 = true;
    const count = Math.floor((nums1.length + nums2.length) / 2);
    if((nums1.length+nums2.length)%2===0){
        let a = null;
        let b = null;
        for(let i = 0;i<count-1;i++){
            if(nums1[index1]===undefined){

                a = nums2[index2+count-i-1];
                b = nums2[index2+count-i];
                return (a+b)/2;
            }
            if(nums2[index2]===undefined){
                a = nums1[index1+count-i-1];
                b = nums1[index1+count-i];
                return (a+b)/2;
            }
            nums1[index1]>nums2[index2]?index2++:index1++;
        }
        if(nums1[index1]===undefined) return (nums2[index2]+nums2[index2+1])/2;
        if(nums2[index2]===undefined) return (nums1[index1]+nums1[index1+1])/2;
        if(nums1[index1]<nums2[index2]){
            a = nums1[index1++];
            if(nums1[index1] && nums1[index1]<nums2[index2]){
                b = nums1[index1]
            }
            else{
                b = nums2[index2];
            }

        }
        else{
            a = nums2[index2++];
            if(nums2[index2] && nums2[index2]<nums1[index1]){
                b = nums2[index2];
            }
            else{
                b = nums1[index1];
            }
        }
        return (a+b)/2;


    }
    else{
        for(let i = 0;i<count+1;i++){
            if(nums1[index1]===undefined){
                return nums2[index2+count-i];
            }
            if(nums2[index2]===undefined){
                return nums1[index1+count-i];
            }
            if(nums1[index1]<nums2[index2]){
                index1++;
                isIndex1 = true;
            }
            else{
                index2++;
                isIndex1=false;
            }
        }
        return isIndex1?nums1[index1-1]:nums2[index2-1];

    }
};



main()
