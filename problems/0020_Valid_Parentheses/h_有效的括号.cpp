class Solution {
public:
    bool isValid(string s) {
    string::iterator ite;
    ite = s.begin();
    stack<int> st;
    char ch;
    int size = s.size();
    for(size_t i = 0; i<size; i++){

        if(*ite == 40 || *ite == 91 || *ite == 123)   //¿ª·Å·ûºÅÈëÕ»
            st.push(*ite);
        if(*ite == 41 || *ite == 93 || *ite == 125){   //·â±Õ·ûºÅµÄ²Ù×÷
            if(st.empty()){
                return false;
            }
            ch = st.top();
            st.pop();
            /****  ·â±Õ·ûºÅÊ±µÄÅä¶Ô²Ù×÷ ***/
            if(*ite == 41 && ch != 40 || *ite == 93 && ch != 91 || *ite == 125 && ch != 123){
                return false;
            }
        }
        ite++;
    }
    return st.empty();
    }    
};
