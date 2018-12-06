object Solution {
    
    // 好数的标准就是包含2，5，6，9中的至少一个（保证翻转后数值不同）并且不能包含3,4,7
    def judgeHao(str:String):Boolean={
        (str.contains("2")||str.contains("5")||str.contains("6")||str.contains("9")) &&(!str.contains("3") && !str.contains("4") &&  !str.contains("7"))
    }
    
    def rotatedDigits(N: Int): Int = {
        var count = 0
        for(i <- 2 toN){
            if(judgeHao(i.toString)){
                count += 1
            }
        }
        count
    }
}
