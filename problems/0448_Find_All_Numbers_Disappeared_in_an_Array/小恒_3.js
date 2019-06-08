var findDisappearedNumbers = function(nums) {
    let count = {}
    let out = []
    
    for(let li of nums){
        count[li] = 1
    }
    for(let i = 1;i <= nums.length;++i){
        if(count[i] !== 1)
            out.push(i)
    }
    return out
};