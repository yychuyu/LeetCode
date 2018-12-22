class L_Solution {

    fun groupAnagrams(strs: Array<String>): List<List<String>> {
        val result=ArrayList<List<String>>()
        var maps: Array<HashMap<Char, Int>?> = arrayOfNulls<HashMap<Char,Int>>(strs.size)
        //拆分每个字符串并用map数组保存
        for (i in strs.indices) {
            val item=strs[i]
            val map=HashMap<Char,Int>()
            for (j in 0 until item.length) {
                val c=item.get(j)
                if(map.containsKey(c)){
                    map.put(c,map[c]!!.plus(1))
                }else{
                    map.put(c,1)
                }
            }
            maps[i]=map
        }

        //遍历map数组
        for(i in 0 until maps.size-1){
            if(maps[i]==null){
                continue
            }
            val list=ArrayList<String>()
            list.add(strs[i])
            for(j in i+1 until maps.size){
                if(maps[j]==null){continue}
                if(checkmap(maps[i],maps[j])){
                    list.add(strs[j])
                    maps[j]=null
                }
            }
            //println(list.toString())
            result.add(list)
        }
        if(maps[maps.size-1]!=null){
            val list=ArrayList<String>()
            list.add(strs[strs.size-1])
            result.add(list)
        }

        return result;
    }

    fun checkmap(map1:Map<Char,Int>?,map2:Map<Char,Int>?):Boolean{
        if(map1!!.size!=map2!!.size){return false}
        for((k,v) in map1){
            if(map2[k]!=v){
                return false
            }
        }
        return true
    }
}