/**
 * @param {number[]} A
 * @param {number} K
 * @return {number}
 */
var largestSumAfterKNegations = function(A, K) {
    A.sort(function(a,b){return a-b;});
    while(A[0] < 0 && K > 0){
        var tmp = A.shift();
        A.push(-tmp);
        K--;
    }
    // 当K>A.length
    if(K%2 == 0){
        return sum(A);
    }
    return sum(A) - 2*Math.min(A[0],A[A.length-1]);
};
function sum(A){
    var re = 0;
    for(var i of A){
        re += i;
    }
    return re;
};