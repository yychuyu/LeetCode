/**
 * @param {number} n
 * @return {number}
 */
var arrangeCoins = function(n) {
    for(let i = 1;; i++){
        if(i * (i + 1) / 2 > n){
            return i-1;
        }
    }
};