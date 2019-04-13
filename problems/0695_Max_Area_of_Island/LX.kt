import java.util.*
import kotlin.math.max

class LX {

    //695. Max Area of Island

    var maxarea=0
    fun maxAreaOfIsland(grid: Array<IntArray>): Int {
        for(i in grid.indices){
            for(j in grid[i].indices){
                if(grid[i][j]==1){
                    var area=dfs(grid,i,j)
                    maxarea= max(maxarea,area)
                }
            }
        }
        return maxarea
    }

    fun dfs(grid:Array<IntArray>,i:Int,j:Int):Int{
        grid[i][j]=0
        var area=1
        if(i-1>=0&&grid[i-1][j]==1){
            area+=dfs(grid,i-1,j)
        }
        if(i+1<=grid.size-1&&grid[i+1][j]==1){
            area+=dfs(grid,i+1,j)
        }
        if(j-1>=0&&grid[i][j-1]==1){
            area+=dfs(grid,i,j-1)
        }
        if(j+1<=grid[i].size-1&&grid[i][j+1]==1){
            area+=dfs(grid,i,j+1)
        }
        return area
    }
}