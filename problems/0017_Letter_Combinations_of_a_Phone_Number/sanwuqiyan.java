class Solution {
	
	
	public List<String> letterCombinations(String digits) {
        char[][] phone = new char[][]{
			{'a','b','c'},  
			{'d','e','f'},    
			{'g','h','i'},    
			{'j','k','l'},    
			{'m','n','o'},    
			{'p','q','r','s'},
			{'t','u','v'},    
			{'w','x','y','z'}
	    };
		List<String> res = new ArrayList<>();
        int len = digits.length();
		if( len == 0 ) return new ArrayList<String>();
		char[][] temp = new char[len][];
		char[] tem = new char[len];
		for( int i=0; i<len; i++ ) {
			temp[i] = phone[digits.charAt(i)-'2'];
		}
        get(res, temp, tem, 0);
        return res;
    }
	public void get(List<String> result, char[][] temp, char[] tem, int index) {
		for( char tmp : temp[index] ) {
			tem[index] = tmp;
			if( index == temp.length-1 ) {
				result.add(new String(tem));
			}else {
				get(result, temp, tem, index+1);
			}
		}
	}
}
