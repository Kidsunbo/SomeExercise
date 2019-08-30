

/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function(n) {
    let result = new Array(n).fill(0).map(x=>new Array(n).fill(0));
    let offset = 1;
    let x = 0;
    let y =0;
    let edgeCode = 0;
    for(let i=1;i<=n*n;i++){
        // fill value
        result[y][x] = i;
        
        // update x and y
        if(edgeCode===0){
            x++;
            if(x+offset===n){
                edgeCode=1;
            }
        }
        else if(edgeCode ===1){
            y++;
            if(y+offset===n){
                edgeCode=2;
            }
        }
        else if(edgeCode===2){
            x--;
            if(x-offset+1===0){
                edgeCode=3;
            }
        }
        else if(edgeCode===3){
            y--;
            if(y-offset===0){
                edgeCode=0;
                offset++;
            }
        }
    }
    return result;
};


window.onload = function () {
    $("#param").keyup(function () {
        try {
            let value = parseInt($("#param").val());
            if (isNaN(value)) throw new Error("");
            $("#output").html("<br/>"+generateMatrix(value)
            .map(x=>"["+x.map(y=>"<span style='display:inline-block;width:30px;'>"+y+"</span>")+"]")
            .join("<br/>"));
        }
        catch (e) {
            $("#output").text("Wrong type");

        }
    });
};