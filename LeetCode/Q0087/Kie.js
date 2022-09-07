/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var isScramble = function(s1, s2) {
    if(s1.length !== s2.length) return false;
    let mem = new Map();
    return isScrambleRecursive(mem, s1, s2, 0, s1.length,0, s2.length);
};


function sameStringWithoutOrder(s1, s2){
    if(s1.length !== s2.length) return false;
    let sum_s1 = 0;
    let sum_s2 = 0;
    for(let i = 0; i<s1.length; i++){
        sum_s1 += s1.charCodeAt(i);
        sum_s2 += s2.charCodeAt(i);
    }
    return sum_s1 === sum_s2;
}

function isScrambleRecursive(mem, s1, s2, s1_start, s1_end, s2_start, s2_end){
    let len = s1_end - s1_start;
    let key = `${s1_start}_${s1_end}_${s2_start}_${s2_end}`;
    if(key in mem){
        return mem[key];
    }
    if(!sameStringWithoutOrder(s1.slice(s1_start, s1_end), s2.slice(s2_start, s2_end))){
        mem[key] = false;
        return false;
    }
    if(len===1){
        mem[key] = true;
        return true;
    }

    for(let i = 1; i<len; i++){
        if(isScrambleRecursive(mem, s1, s2, s1_start, s1_start+i, s2_start, s2_start+i) &&
            isScrambleRecursive(mem, s1, s2, s1_start+i, s1_end, s2_start+i, s2_end) ||
            isScrambleRecursive(mem,s1,s2, s1_start, s1_start+i, s2_end-i, s2_end) &&
            isScrambleRecursive(mem, s1, s2, s1_start+i, s1_end, s2_start, s2_end-i)){
            mem[key] = true;
            return true;
        }
    }
    mem[key] = false;
    return false;
}

console.log(isScramble("eebaacbcbcadaaedceaaacadccd",
"eadcaacabaddaceacbceaabeccd"));


