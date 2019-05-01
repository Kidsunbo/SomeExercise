/**
 * @param {number} dividend
 * @param {number} divisor
 * @return {number}
 */
var divide = function(dividend, divisor) {
    dividend= parseInt(dividend);
    divisor = parseInt(divisor);
    if(dividend===(-2)**31 && divisor===-1) return 2**31-1;
    if(Math.abs(dividend)<Math.abs(divisor)) return 0;
    let sign = (divisor>0)^(dividend>0);
    dividend=-Math.abs(dividend);
    divisor=-Math.abs(divisor);

    let count = 0;
    while (dividend<=divisor) {
        let s= -1;
        let m = divisor;
        while(dividend-m<=m){
            s=s+s;
            m=m+m;
        }
        count+=s;
        dividend-=m;
    }
    return sign?count:-count;
};

window.onload=function () {
    $("#param").keyup(function () {
        let values = $("#param").val().split(",");
        if(values[1]&&values[1]!=="") {
            $("#output").text(divide(...values));
        }

    })
};