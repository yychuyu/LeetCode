#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int> & vec)
{
    if(vec.empty())
        return 0;

    int index = 0;
    int size = vec.size();
    for(int i=1;i<size;i++){
        if(vec[index] != vec[i])
            vec[++index]=vec[i];
    }
    return index+1;
}

int main(){
    std::vector<int> vec = {1,1,2,2,2,3,3,4,4,5};
    std::cout << "new length:" << removeDuplicates(vec) << std::endl;
    for(auto i : vec){
        std::cout << i << "\t" ;
    }
    std::cout << std::endl;
    return 0;
}
