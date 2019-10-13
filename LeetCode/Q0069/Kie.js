
/**
 * @param {number} x
 * @return {number}
 */
// Time 86.70%  Memory 83.33%
var mySqrt = function(x) {
    let min = 0;
    let max = x;

    while(min<max){
        let mid = Math.floor((min+max)/2);
        let r = mid*mid;
        if(r<x) min=mid+1;
        else if(r>x) max = mid-1;
        else return mid;
    }
    if(max*max>x) return max-1;
    return max;
};

window.onload=function () {

    $("#param").keyup(function () {
            let val = parseInt($("#param").val());
            if(val===val)
                $("#output").text(mySqrt(val))
    })
};