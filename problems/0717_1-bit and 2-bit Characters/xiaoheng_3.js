var isOneBitCharacter = function(bits) {
    let i = 0
    
    while(i < bits.length-1){
        i = bits[i] === 0 ? i + 1 : i + 2
    }
    
    return i === bits.length-1 && bits[bits.length-1] === 0
};