class LX {
/**
*994 Rotting Oranges
*/
    fun orangesRotting(grid: Array<IntArray>): Int {

        var count:Int=0;
        while (true){
            var xlist=ArrayList<Int>()
            var ylist=ArrayList<Int>()
            var has_1:Boolean=false
            var has_2:Boolean=false
            var hasganran:Boolean=false
            for (i in grid.indices){
                val array=grid[i]
                for(j in grid[i].indices){
                    //print(""+grid[i][j]+" ")
                    if(grid[i][j]==1){
                        has_1=true
                    }
                    if(grid[i][j]==2){
                        has_2=true;
                        xlist.add(i)
                        ylist.add(j)
                        //hasganran=ganran(grid,i,j)
                    }
                }
                //println()
            }
            for(i in xlist.indices){
                if(ganran(grid,xlist[i],ylist[i])){
                    hasganran=true
                }
            }
            count++
            if(hasganran==false&&has_1==true){
                return -1
            }
//            if(has_1==false&&has_2==false){
//                return 0
//            }

            if(has_1==false){
                return count-1
            }
            if(has_2==false){
                return -1
            }
        }
        //return -1;
    }

    fun ganran(grid: Array<IntArray>,x:Int,y:Int):Boolean{
        var hasganran:Boolean=false
        if(x-1>=0&&grid[x-1][y]==1){
            grid[x-1][y]=2
            hasganran=true;
        }
        if(y-1>=0&&grid[x][y-1]==1){
            grid[x][y-1]=2
            hasganran=true;
        }
        if(x+1<grid.size&&grid[x+1][y]==1){
            grid[x+1][y]=2
            hasganran=true;
        }
        if(y+1<grid[x].size&&grid[x][y+1]==1){
            grid[x][y+1]=2
            hasganran=true;
        }
        return hasganran
    }
}