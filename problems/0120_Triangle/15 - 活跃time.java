class Solution {

	public int minimumTotal(List<List<Integer>> triangle) {
		int i = 0, j = 0;
		int pe, af;

		for (i = 1; i < triangle.size(); i++) {
			triangle.get(i).set(0, triangle.get(i - 1).get(0) + triangle.get(i).get(0));
			for (j = 1; j < i; j++) {
				pe = triangle.get(i - 1).get(j);
				af = triangle.get(i - 1).get(j - 1);
				if (pe < af)
					triangle.get(i).set(j, pe + triangle.get(i).get(j));
				else
					triangle.get(i).set(j, af + triangle.get(i).get(j));
			}
			triangle.get(i).set(i, triangle.get(i - 1).get(i - 1) + triangle.get(i).get(i));
		}

		return Collections.min(triangle.get(triangle.size() - 1));
	}

}