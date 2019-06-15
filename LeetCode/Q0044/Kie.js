/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    if(s.length===0 && p.length===0) return true;
    if(s.length*p.length===0) return false;
    let first_star = 0;
    let last_star = p.length-1;
    while(true){
        if(p[first_star]==='*') break;
        first_star++;
    }
    while(true){
        if(p[last_star]==='*') break;
        last_star--;
    }
    if(first_star===last_star){

    }

};

window.onload=function () {
    $("#param").keyup(function () {
        let values = $("#param").val().split("|");

        if(values[1]&&values[1]!=="") {
            $("#output").text(isMatch(values[0],values[1]));
        }

    })
};