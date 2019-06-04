/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {

};

window.onload=function () {
    $("#param").keyup(function () {
        let values = $("#param").val().split(",").map(x=>parseInt(x));
        if(values[1]&&values[1]!=="") {
            $("#output").text();
        }

    })
};