/*
  题目：
  给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
  
  示例 1:
  输入: "Let's take LeetCode contest"
  输出: "s'teL ekat edoCteeL tsetnoc"
*/
class Solution {
public:
    string reverseWords(string s) {
        if(s.empty()){
            return s;
        }
        
        for(int i=0; i<=s.size()-1; i++){
            if( s[i] != ' ' ){//找到单词的开头           
                for(int j=i; j<=s.size()-1; j++){//找到单词的结尾
                    if( s[j+1] == ' ' || j+1 == s.size() ){     
                        int left = i;        
                        int right =  j;      
                        while(left < right){           
                            swap(s[left], s[right]);           
                            left++;           
                            right--;       
                        }     
                        
                        i=j+1;
                        break;
                    }
                }//end of for(j)  
            }   
        }//end of for(i)   
        
        return s;
    }
};
