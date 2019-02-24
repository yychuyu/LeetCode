#include <iostream>
#include <vector>


int removeDuplicates(std::vector<int>& nums)
{
    int index = 0;
    if (nums.size() == 0)
    {
        return 0;
    }
    for (auto & element: nums)
    {
        if (element > nums[index])
        {
            index += 1;
            nums[index] = element;
        }

    }
    return index+1;
}


int main()
{
    std::vector<int> v = {1, 1, 2, 2, 3, 4};
    int duplicates = removeDuplicates(v);
    std::cout << duplicates << std::endl;

    return 0;
}
