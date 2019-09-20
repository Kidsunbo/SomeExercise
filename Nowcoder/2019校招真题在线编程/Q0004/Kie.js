num = parseInt(readline());
map = new Map();
str = readline();
for(let i of str){
    if(map.has(i)) map.set(i,map.get(i)+1);
    else map.set(i,1);
}
if(map.size===0){
    console.log('N');
}
else if(map.size===1){
    if(map.has('L')){
        console.log('NWSE'[map.get('L')%4]);
    }else{
        console.log('NESW'[map.get('R')%4]);
    }
}
else{
    if(map.get('L')>map.get('R')){
        console.log('NWSE'[(map.get('L')-map.get('R'))%4]);
    }else{
        console.log('NESW'[(map.get('R')-map.get('L'))%4]);
    }
}