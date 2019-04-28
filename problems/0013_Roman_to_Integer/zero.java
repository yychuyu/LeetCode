class Solution {
    public int romanToInt(String s) {
        Map singleRomanNumber = new HashMap<String,Integer>();
        singleRomanNumber.put("I",1);
        singleRomanNumber.put("V",5);
        singleRomanNumber.put("X",10);
        singleRomanNumber.put("L",50);
        singleRomanNumber.put("C",100);
        singleRomanNumber.put("D",500);
        singleRomanNumber.put("M",1000);

        int romanNumber = 0;
        for(int i = 0 ;i < s.length(); i++){
            if (i < s.length() -1 && (Integer)singleRomanNumber.get( s.substring(i,i+1) ) < (Integer) singleRomanNumber.get(  s.substring(i+1,i+2))){
                romanNumber -= (Integer) singleRomanNumber.get( s.substring(i,i+1) );
            }else{
                romanNumber += (Integer) singleRomanNumber.get( s.substring(i,i+1) );
            }
        }
        return romanNumber;
    }
}