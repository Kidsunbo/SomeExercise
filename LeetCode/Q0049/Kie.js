/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    let result = new Map();
    let add = [...strs];
    add =add.map(x=>[...x].reduce((x,y)=>x+y.charCodeAt(0),0));
    let mul = [...strs];
    mul = mul.map(x=>[...x].reduce((x,y)=>x*y.charCodeAt(0),1));
    for(let i =0;i<strs.length;i++){
        let key = new Key(add[i],mul[i],strs[i].length).key;
        if(result.has(key)){
            result.get(key).push(strs[i]);
        }
        else{
            result.set(key,[strs[i],]);
        }
    }
    console.log(result.keys());
    return [...result.values()];

};

class Key{
    constructor(add,mul,len){
        this.add = add;
        this.mul = mul;
        this.len = len;
    }

    get key(){
        return Symbol.for(`${this.add} ${this.mul} ${this.len}`);
    }
}

window.onload=function () {
    $("#param").keyup(function () {
        let values = eval($("#param").val());
        if(values.length>1) {
            $("#output").text(groupAnagrams(values));
        }
    })
};