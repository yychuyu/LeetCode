/*
 * ZigZag Conversion.c
 *
 * April 29,2019 
 *
 * Author:lkk789@aliyun.com
 *
 */
 
 /*
 将字符串 "PAYPALISHIRING" 以Z字形排列成给定的行数：

P A H N
A P L S I I G
Y I R

之后从左往右，逐行读取字符： "PAHNAPLSIIGYIR"

实现一个将字符串进行指定行数变换的函数:

string convert(string s, int numRows);

示例 1:

输入: s = "PAYPALISHIRING", numRows = 3
输出: "PAHNAPLSIIGYIR"

示例 2:

输入: s = "PAYPALISHIRING", numRows = 4
输出: "PINALSIGYAHRPI"
解释:

P I N
A L S I G
Y A H R
P I
 */


/**
* ZigZag Conversion
* Z字形变换
*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;
string convert(string s, int nRows) {
    //The cases no need to do anything
    if (nRows<=1 || nRows>=s.size()) return s;
     
    vector<string> r(nRows);
    int row = 0;
    int step = 1;
    for(int i=0; i<s.size(); i ++) {
        if (row == nRows-1) step = -1;
        if (row == 0) step = 1;
        //cout << row <<endl;
        r[row] += s[i];
        row += step;
    }
    
    string result;
    for (int i=0; i<nRows; i++){
        result += r[i];
    }
    return result;
}
int main(int argc, char**argv){
    string s;
    int r;
    s = "PAYPALISHIRING";
    r = 3;
    cout << s << " : " << convert(s, 3) << endl;
}