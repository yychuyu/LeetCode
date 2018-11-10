/**
 * 	the website about the detail for the problem:
 *	https://leetcode.com/problems/integer-to-roman/description/
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {

        // 定义映射数据结构
        struct keyValue
        {
            char symbol;
            int value;
        };

        // 初始化映射键值对vector容器
        vector<keyValue> key_val{{'I', 1},
                                 {'V', 5},
                                 {'X', 10},
                                 {'L', 50},
                                 {'C', 100},
                                 {'D', 500},
                                 {'M', 1000}
        };


        string res;              // 保留结果的字符串
        vector<int> arr;         // 保留拆分的数字的数组

        int tmp = num;          // 拷贝num
        // 将数字拆分后放置在数组arr中
        while (0 != tmp / 10)
        {
            arr.push_back(tmp % 10);
            tmp /= 10;
        }
        arr.push_back(tmp);             // tmp = abcd ---> 在数组中存为[dcba]

        // vector容器的大小
        auto sz = arr.size();           // 无符号数，注意！！！

        // 数据处理过程
        while (0 != sz)
        {
            int pw = static_cast<int>(pow(10, sz-1));      // 幂次(1, 10, 100, 1000)

            // 得到相关系的一组罗马数字集合
            string s_tmp;       // 存储可能用到的罗马数字集合
            int i;
            for (i = 0; i < key_val.size(); ++i)
            {
                if (pw == key_val[i].value)
                {
                    s_tmp += key_val[i].symbol;
                    break;
                }
            }

            if (pw < 1000)
            {
                for (int j = i + 1; j <= i + 2; j++)
                {
                    s_tmp += key_val[j].symbol;
                }
            }


            // 当前位的数字
            int cur = arr[sz-1];

            // 处理千位上的数字
            if (s_tmp.size() != 3)
            {
                while (cur-- > 0)
                {
                    res += s_tmp;
                }
            }
            else    // 处理百位、十位、个位上的数字
            {
                switch (cur)
                {
                    case 1:
                    case 2:
                    case 3:
                    {
                        while (cur-- >0)
                        {
                            res += s_tmp[0];
                        }
                        break;
                    }
                    case 4:
                    {
                        res += s_tmp[0];
                        res += s_tmp[1];
                        break;
                    }
                    case 5:
                    {
                        res += s_tmp[1];
                        break;
                    }
                    case 6:
                    case 7:
                    case 8:
                    {
                        cur -= 5;
                        res += s_tmp[1];
                        while (cur-- >0)
                        {
                            res += s_tmp[0];
                        }
                        break;
                    }
                    case 9:
                    {
                        res += s_tmp[0];
                        res += s_tmp[2];
                        break;
                    }
                    default:
                        break;
                }
            }

            --sz;
        }


        return res;
    }
};



/*
int main(int argc, char const *argv[])
{
    Solution a;
    int num;
    while (cin >> num)
    {
        cout << a.intToRoman(num) << endl;
    }

    return 0;
}
*/

