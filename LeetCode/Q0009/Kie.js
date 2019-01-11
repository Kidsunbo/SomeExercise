/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if(x < 0) return false;
    let digitCount = 1;
    let temp = x;
    while(Math.floor(temp/=10)) digitCount++;
    for(let left = 0;left<Math.ceil(digitCount/2);left++)
        if(Math.floor(x/(10**(digitCount-left-1)))%10 !== Math.floor(x/(10**left))%10)
            return false;

    return true;

};


$(document).ready(function () {
    $("#param").keyup(function () {
        isPalindrome(Number.parseInt($("#param").val()));
        $("#output").text(isPalindrome(Number.parseInt($("#param").val())));
    })

});