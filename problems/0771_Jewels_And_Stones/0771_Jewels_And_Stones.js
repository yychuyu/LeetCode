/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
var numJewelsInStones = function(J, S) {
    var i,k,count=0;
    for(i=0;S[i];i++)
    {
        for(k=0;J[k];k++)
        {
            if(J[k]==S[i])
                count++;
        }
    }
return count;
};