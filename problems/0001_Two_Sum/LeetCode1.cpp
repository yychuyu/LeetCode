/*
知识点：
map使用：https://blog.csdn.net/sevenjoin/article/details/81943864
点1、map中find的使用：
当所查找的关键key出现时，它返回数据所在对象的位置，如果沒有，返回iter与end函数的值相同。
// find 返回迭代器指向当前查找元素的位置否则返回map::end()位置
    
    iter = mapStudent.find("123");     
    if(iter != mapStudent.end())
        cout<<"Find, the value is"<<iter->second<<endl;
    else
        cout<<"Do not Find"<<endl;
        
点2、vector中push_back函数的使用：
C++ push方法与push_back方法：https://www.cnblogs.com/xxyue/p/9051509.html

    push_back 方法介绍

    vector::void push_back (const value_type& val);

    vector::void push_back (value_type&& val);

    该函数将一个新的元素加到vector的最后面，位置为当前最后一个元素的下一个元素，新的元素的值是val的拷贝（或者是移动拷贝）

*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solutinon{
    public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        map<int,int> m;
        vector<int> result;
        for(int i = 0; i < numbers.size(); i++)
        {
            if(m.find(numbers[i]) == m.end()){
                m[target-numbers[i]] = i;
            }
            else{
                result.push_back(m[numbers[i]] + 1);
                result.push_back(i + 1);
                break;
            }
        }
        return result;
    }
};

int main()
{
    int num[4] = {2,11,7,15};
    Solutinon method;
    vector<int> arr(num,num+4);
    vector<int> index;
    int target = 9;
    index = method.twoSum(arr,target);
    cout <<"index[1] = "<< index[0] << endl << "index[2] = " << index[1] << endl;
    return 0;
}