/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    if(matrix.length===0) return [];
    let result = [];
    let [dir_x,dir_y,cur_x,cur_y,offset]=[1,0,0,0,0];

    while(true){
        // Judge dir_x and dir_y
        if(dir_x===1 && cur_x+offset===matrix[cur_y].length-1) [dir_x,dir_y]=[0,1];
        else if(dir_x === -1&&cur_x-offset===0) [dir_x,dir_y]=[0,-1];
        else if(dir_y === 1 && cur_y+offset===matrix.length-1) [dir_x,dir_y]=[-1,0];
        else if(dir_y===-1 && cur_y-offset-1===0) [dir_x,dir_y,offset]=[1,0,offset+1];
        // Push
        result.push(matrix[cur_y][cur_x]);
        if(result.length===matrix.reduce((p,n)=>p+n.length,0)) return result;
        // Update cur_x and cur_y
        cur_x = cur_x+dir_x;
        cur_y = cur_y+dir_y;
    }
};


window.onload=function () {
    String.prototype.replaceAll = function(target, replacement) {
        return this.split(target).join(replacement);
    };
    $("#param").keyup(function () {
        let values = $("#param").val();
        if(values.endsWith('#')){
            values = values.replace("#","");
        }

        if(values.length>1) {
            $("#output").html(spiralOrder(eval(values)).join(","));
        }
    })
};