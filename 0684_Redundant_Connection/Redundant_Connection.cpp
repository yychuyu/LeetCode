/*
  题目：
  给定一组边，以形成一颗树，其中有一条多余（会使树中出现环），找出这条边。

  参考：
  https://blog.csdn.net/liao_zx/article/details/78385737
*/

class Solution {
public:
    int findParent(map<int,int>& parent,int k){
        if( parent.find(k)!=parent.end() ){
           return findParent(parent,parent[k]);
        }
        return k;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map<int,int> parent;        
        int point1=0,point2=0;
        
        for(int i=0; i<edges.size(); i++){            
            point1=findParent(parent, edges[i][0]);
            point2=findParent(parent, edges[i][1]);           
            if(point1==point2){
                return edges[i];
            }
            parent.insert( pair<int,int>(point2,point1) );
        }
        
        return vector<int>(0,0);
    }
};
