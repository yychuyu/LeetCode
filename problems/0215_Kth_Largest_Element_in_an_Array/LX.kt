import java.util.*

class LX {

    //Kth Largest Element in an Array

    fun findKthLargest(nums: IntArray, k: Int): Int {
        var ak= arrayOfNulls<Int>(k+1)
        for(i in ak.indices){
            ak[i]=Int.MIN_VALUE;
        }
        for(i in nums.indices){
            if(nums[i]>ak[1]!!){
                ak[0]=nums[i]
                Arrays.sort(ak)
            }
        }
        return ak[1]!!
    }
}