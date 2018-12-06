#include <iostream>
#include <vector>
using std::vector;


void merge(vector<int>& va,int m,vector<int> &vb,int n)
{
    int ia = m -1,ib = n-1,icur = m + n -1;
    while(ia >= 0 && ib >=0)
    {
        va[icur--] = va[ia] >= vb[ib]?va[ia--]:vb[ib--];
    }
    while(ib>=0)
    {
        va[icur--] = vb[ib--];
    }
}

int main(){
    vector<int> va = {3,6,8,13,15,19};
    int m = va.size();
    vector<int> vb = {1,4,7,9,11,13,14,20};
    va.resize(va.size()+vb.size());
    merge(va,m,vb,vb.size());
    for(auto i : va)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
