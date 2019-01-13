/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if(strs.length===0) return "";
    if(strs.length===1) return strs[0];
    let result = "";
    let index =0;
    while (true) {
        for (let i = 1; i < strs.length; i++) {
            if (strs[0][index] === undefined || strs[0][index] !== strs[i][index]) return result;
        }
        result+=strs[0][index];
        index++;
    }
};


$(document).ready(function () {
    $("#output").text(longestCommonPrefix(["dog"]))

});