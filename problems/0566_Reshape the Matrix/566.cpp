//将二维数组转换为一维，再将一维数组转换为二维
/*
1、size()是取字符串长度的，跟length()用法相同。、
2、sizeof(...)是运算符，其值在编译时即计算好了，参数可以是数组、指针、类型、对象、函数等。
它的功能是：获得保证能容纳实现所建立的最大对象的字节大小。由于在编译时计算，因此sizeof不能用来返回动态分配的内存空间的大小。
*/
vector<vector<int>> matrixReshape(vector<vector<int>> &nums,int r, int c)
{
    int m = nums.size(), n =nums[0].size();
    if (m*n !=  r*c)
        return nums;//返回原数组
    vector<vector<int>> res(r, vector<int>(c));
    for (int i =0;i < r;i++){
        for (int j = 0;j < c;j++){
            int k = i*c +j;//将原数组转换为一个一维数组
            res[i][j] = nums[k/n][k%n];//转换为新的二位数组
        }
    }
    return res;
}