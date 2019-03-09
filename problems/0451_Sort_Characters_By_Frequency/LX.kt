class LX {

    //451.Sort Characters By Frequency

    fun frequencySort(s: String): String {
        var stringbuffer=StringBuffer()
        var map=HashMap<Char,Int>()
        for(i in s){
            if(map.containsKey(i)){
                map.put(i,map.get(i)!!+1)
            }else{
                map.put(i,1);
            }
        }
        //println(map.toString())
        while (!map.isEmpty()){
            var c:Char='1'
            var max=-1;
            for ( (k,v) in map){
                if(v>max){
                    max=v
                    c=k
                }
            }
            for (i in 0 until max) {
                stringbuffer.append(c)
            }
            map.remove(c)
        }
        return stringbuffer.toString()
    }
}