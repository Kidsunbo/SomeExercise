/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    let c = Math.min(...candidates);
    let result = [];
    let maxLoop = Math.floor(target/c);
    for(let i=maxLoop;i>0;i--){
        let r = findResult(candidates,target,i);
        if(r.length!==0)result.push(...r);
    }
    return result;
};

var findResult = function(candidates, target,n){
    let indexes = new Array(n).fill(0);
    let result = [];
    while(indexes.some(x=>x<candidates.length-1)){
         if(sum(candidates,indexes)===target){
             result.push(indexToCand(candidates,indexes))
         }
        updateIndexes(indexes,candidates.length-1);
    }
    if(sum(candidates,indexes)===target) result.push(indexToCand(candidates,indexes));
    return result;
};

var indexToCand = function(candidates,indexes){
    let result =[];
    for(let i of indexes){
        result.push(candidates[i]);
    }
    return result;
};

var sum = function(candidates,indexes){
    let s =0;
    for(let i of indexes){
        s+=candidates[i];
    }
    return s;
};

var updateIndexes = function(indexes,n){
    for(let i=indexes.length-1;i>=0;i--){
        if(indexes[i]===n) continue;
        indexes[i]++;
        for(let j =i+1;j<indexes.length;j++){
            indexes[j]=indexes[i];
        }
        break;
    }
};

window.onload=function () {
    $("#param").keyup(function () {
        let values = $("#param").val().split("|");
        let candidates = values[0].split(",").map(x=>parseInt(x));
        if(values[1]&&values[1]!=="") {
            $("#output").text(combinationSum(candidates,parseInt(values[1])));
        }

    })
};