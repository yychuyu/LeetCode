/**
 * @param {string} str
 * @return {string}
 */
var toLowerCase = function(str) {
    var i = 0;
    while(str[i])
    {
        if(  (str[i]>='A')
           &&(str[i]<='Z')
        )
        {
            str[i] ^= 32;
        }
        i++;
    }
    
    return str;
};