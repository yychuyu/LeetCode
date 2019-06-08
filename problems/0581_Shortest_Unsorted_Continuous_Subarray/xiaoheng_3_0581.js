var findUnsortedSubarray = function(nums) {
    
    let [left, right, Nums] = [0, nums.length-1, [...nums]];

    nums.sort((x,y)=>x-y);
    
    while(right > left){
        nums[left] === Nums[left] && left++;
        nums[right] === Nums[right] && right--;
        
        if(nums[left] !== Nums[left] && nums[right] !== Nums[right]) break;
    }
    
    return right === left ? 0 : right-left+1;
};