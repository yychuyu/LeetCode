class Solution {
public:
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> temp;   //�ݴ�out�е�Ԫ��
        vector<vector<int>> out;    //����Ķ�ά����
        out.push_back(temp);    //�� '[]' ������
        
        for(int i = 0;i < nums.size();i++){     //����nums�е�Ԫ��
            
            int len = out.size();   //�ݴ�out���ȣ���Ϊ������
            for(int j = 0; j < len;j++){    //����out
                
                temp = out[j];
                temp.push_back(nums[i]);
                out.push_back(temp);
                
            }
        }
        
        return out;
    }   
};
