class Lonecloud {
    public int lengthOfLongestSubstring(String s) {
        //如果是0 怎直接去除
        if(s==null||s.length()==0)return 0;
        //定义每个字符串的位置
        Map<Character,Integer> mapperMap=new HashMap<>();
        //子串位置
        int start=0;
        //最大长度
        int maxLen=0;
        //数组转换
        char[] chars = s.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            //获取目标index
            char indexChar = chars[i];
            //如果存在，则说明有重复字符串则
            if (mapperMap.containsKey(indexChar)){
                //获取下标值
                Integer sameIndex = mapperMap.get(indexChar);
                //startLen->sameIndex+1
                //该下标和之前开始的子串位置比较大小，然后取最大值
                start=Math.max(start,sameIndex+1);
            }
            //计算长度取最大值
            maxLen=Math.max(maxLen,i-start+1);
            //将子串put到Map中
            mapperMap.put(indexChar,i);
        }
        //返回最大不重复子串
        return maxLen;
    }
}
