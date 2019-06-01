class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        
        if(r*c != nums.length*nums[0].length) return nums;
        
        Result result = new Result(new int[r][c]);
        for(int i = 0; i < nums.length; i++){
            for(int j = 0; j < nums[i].length; j++){
                result.set(nums[i][j]).next();
                
            }
        }
        
        return result.result;
    }
}

class Result{
    int[][] result;
    int i, j;
    
    Result(int[][] result){
        this.result = result;
    }
    
    void next(){
        j++;
        if(j >= result[i].length){
            j = 0;
            i++;
        }
    }
    
    int get(){
        return result[i][j];
    }
    
    Result set(int a){
        result[i][j] = a;
        return this;
    }
    
}