/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    let result = [];
    for(let i of new Array(p.length+1))
        result.push(new Array(s.length+1).fill(false));
    result[0][0] =true;
    for(let i = 0;i<=p.length;i++){
        if(p[i]==="*") result[i+1][0]=result[i][0];
    }

    for(let i =1; i <= p.length; i++){
        for(let j = 1;j<=s.length;j++){
            if(s[j-1]===p[i-1] || p[i-1]==='?') result[i][j]=result[i-1][j-1];
            else if(p[i-1]==="*"){
                result[i][j] =result[i-1][j] ||result[i][j-1];
            }
        }
    }
    return result[p.length][s.length];
};

window.onload=function () {
    $("#param").keyup(function () {
        let values = $("#param").val().split("|");

        if(values[1]&&values[1]!=="") {
            $("#output").text(isMatch(values[0],values[1]));
        }

    })
};