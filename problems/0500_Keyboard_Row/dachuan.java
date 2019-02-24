class Solution {
    public String[] findWords(String[] words) {
        char[] one = {'q','w','e','r','t','y','u','i','o','p'};
        char[] two = {'a','s','d','f','g','h','j','k','l'};
        char[] three = {'z','x','c','v','b','n','m'};
        String[] result = null;
        String[] tmp = new String[words.length];
        int num = 0;
        for (int i = 0; i < words.length; i++) {
            String str = words[i];
            String strLower = str.toLowerCase();
            char[] chars = strLower.toCharArray();
            if(isContain(chars, one)||isContain(chars, two)||isContain(chars, three)){
            	tmp[i] = words[i]; 
            	num++;
            }
        }
        result = new String[num];
        int x = 0;
        for (int i = 0; i < tmp.length; i++) {
			if(tmp[i] != null){
				result[x]= tmp[i];
				x++;
			}
		}
     return result;
    }
	private boolean isContain(char[] other, char[] compared){
		for (int i = 0; i < other.length; i++) {
			boolean everyResult = false;
			for (int j = 0; j < compared.length; j++) {
				if(other[i] == compared[j]){
					everyResult = true;
				}
			}
			if(!everyResult){
				return false;
			}
		}
		return true;
    }
}