import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Set;



public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Test test = new Test();
		int[] candidates = {5,10,8,4,3,12,9};

		List<List<Integer>> res = test.combinationSum(candidates, 27);
		System.out.println(res);
	}

	public List<List<Integer>> combinationSum(int[] candidates, int target) {

		List fuck = new LinkedList<Integer>();
		List<List<Integer>> real=new LinkedList<>();

		for (int i = 0; i < candidates.length; i++) {
			fuck.add(candidates[i]);

		}

		List<List<Integer>> res = recurse(fuck, target);
		if(res==null) {
			return real;
		}
		List tempuse=null;
		
				
		int test=0;
		for(int i=0;i<res.size();i++) {
			for(int j=0;j<res.get(i).size();j++) {
				test=test+res.get(i).get(j);
			}
			
			if(test==target) {
				tempuse=new LinkedList<>(res.get(i));
				real.add(tempuse);
			}
			test=0;
		}
		
		
		//去掉重复元素
		int[]a=null;
		List<List<Integer>> rreal=new LinkedList<>();
		
		for(int i=0;i<real.size();i++) {
			a=new int[real.get(i).size()];
			for(int j=0;j<real.get(i).size();j++) {
				a[j]=real.get(i).get(j);
				
			}
			
			Arrays.sort(a);
			List bList=new LinkedList<Integer>();
			for(int j=0;j<real.get(i).size();j++) {
				bList.add(a[j]);
			}
			rreal.add(bList);
			
			//System.out.println(bList.toString());
		}
		
		/*List<List<Integer>> chongfu=new LinkedList<>();
		List<List<Integer>> buchongfu=new LinkedList<>();
		
		for(int i=0;i<rreal.size();i++) {
			for(int j=0;j<rreal.size();j++) {
				if(i!=j) {
					if(rreal.get(i).toString()==rreal.get(j).toString()) {
						
					}
				}
			}
		}*/
		Set set=new HashSet<List>();
		
		for(int i=0;i<rreal.size();i++) {
			set.add(rreal.get(i));
		}
		
		List<List<Integer>> rrreal=new LinkedList<>(set);


		return rrreal;
	}

	public List<List<Integer>> recurse(List<Integer> candidates, int target) {

		List<List<Integer>> temp = null;
		List<List<Integer>> result = new LinkedList<>();

		List tempuse = null;

		int newtarget = 0;
		List newintList = null;

		if (target <= 0 || candidates.size() == 0)
			return null;

		/*if (candidates.size() == 1) {
			if (candidates.get(0) == target) {
				tempuse = new LinkedList<Integer>();
				tempuse.add(candidates.get(0));
				result.add(tempuse);
				return result;
			} else {
				return null;
			}
		}*/

		for (int i = 0; i < candidates.size(); i++) {
			newtarget = target - candidates.get(i);

			newintList = new LinkedList<>(candidates);
			//newintList.remove(i);

			temp = recurse(newintList, newtarget);

			if (temp != null) {

				for (int j = 0; j < temp.size(); j++) {
					tempuse = new LinkedList<>(temp.get(j));
					tempuse.add(candidates.get(i));
					result.add(tempuse);
				}

			}else {
				tempuse=new LinkedList<Integer>();
				tempuse.add(candidates.get(i));
				result.add(tempuse);
			}

		}

		return result;
	}
}
