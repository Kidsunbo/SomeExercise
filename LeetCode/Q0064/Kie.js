/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function(grid) {
    if(grid.length===0) return;
    let storage = new Array(grid.length).fill(0).map(()=>{return new Array(grid[0].length).fill(0);});

    storage[0][0] = grid[0][0];
    // first column
    for(let i =1;i<grid.length;i++){
        storage[i][0]  = storage[i-1][0]+grid[i][0];
    }
    // first row
    for(let i=1;i<grid[0].length;i++){
        storage[0][i] = storage[0][i-1]+grid[0][i];
    }
    // start
    for(let i =1;i<grid.length;i++){
        for(let j = 1;j<grid[i].length;j++){
            storage[i][j]=Math.min(storage[i-1][j],storage[i][j-1])+grid[i][j];
        }
    }

    // get result
    return storage[grid.length-1][grid[0].length-1];
};


window.onload=function () {

    $("#param").keyup(function () {
        try {
            let values = eval($("#param").val());
            if (values.length >= 1) {
                $("#output").html(minPathSum(values));
            }
        }
        catch (e) {}
    })
};