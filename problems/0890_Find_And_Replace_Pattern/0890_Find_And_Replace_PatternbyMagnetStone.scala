import scala.collection.mutable.ArrayBuffer

object Solution {
    def findAndReplacePattern(words: Array[String], pattern: String): List[String] = {
        
      def strMatch(word: String, pattern: String):Boolean={
            for(i <- 0 until word.length; j <- i + 1 until word.length){
                if ((pattern(i) == pattern(j)) && (word(i) != word(j))) {
					return false
                }
                if ((pattern(i) != pattern(j)) && (word(i) == word(j))) {
					return false
                }
            }
			return true
        }  
        
      val empty = new ArrayBuffer[String]()
      for(word <- words){
        if(word.length == pattern.length){
            if(strMatch(word, pattern)){
                empty.append(word)
            }
        }
      }
      empty.toList
    }
}
