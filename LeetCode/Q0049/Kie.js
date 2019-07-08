/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {

    let result = new Map();
    let ind = [...strs];
    const prime = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101];
    ind = ind.map(x=>[...x].reduce((x,y)=>x*prime[y.charCodeAt(0)-"a".charCodeAt(0)],1));
    for(let i =0;i<strs.length;i++){
        if(result.has(ind[i])){
            result.get(ind[i]).push(strs[i]);
        }
        else{
            result.set(ind[i],[strs[i]]);
        }
    }
    return [...result.values()];

};


window.onload=function () {
    String.prototype.replaceAll = function(target, replacement) {
        return this.split(target).join(replacement);
    };
    $("#param").keyup(function () {
        let values = eval($("#param").val().replaceAll(`"`,"").replaceAll(" ","").split(","));

        if(values.length>1) {
            $("#output").html(groupAnagrams(values));
        }
    })
};