import java.util.HashMap;
import java.util.Map;



class TwoSum {
//思路1
//双层for循环遍历数组
//类似选择排序，两两相加
//       若等于target则输出
//       若不等则下一个
//若没有找到则抛出异常
//	public static int[] twoSum(int[] nums, int target) {
//		for(int x=0;x<nums.length;x++){
//			for(int y=(x+1);y<nums.length-1;y++){
//				if(nums[y]==(target-nums[x])){
//					return new int[] {x,y};
//				}
//			}		
//		}
//		throw new IllegalArgumentException("No two sum solution");
//	}
	
	//思路2
	//1.创建一个HashMap
	//2.循环遍历nums数组，在HashMap中找目标值减去索引值的结果
	//	a.若找到了，输出这个数组
	//	b.若没找到，将这个索引，索引值为键值对存入HashMap中
	//3.时间复杂度：O(n)
	//	空间复杂度：O(1)
	public static int[] twoSum(int[] nums, int target) {
		Map<Integer,Integer> hashMap = new HashMap<>();
		for(int i=0;i<nums.length;i++){
			int aaa = target-nums[i];
			if(hashMap.containsValue(aaa)){
				return new int[]{hashMap.get(aaa),i};
			}			
			hashMap.put(nums[i], i);
			
		}
		throw new IllegalArgumentException("No two sum solution");
	}

	
	
//测试代码
	public static void main(String[] args) {
		int[] arr = { 2, 3, 4, 5 };
		int[] arr2 = twoSum(arr, 7);
		for (int i : arr2) {
			System.out.println(i);
		}
	}
}
