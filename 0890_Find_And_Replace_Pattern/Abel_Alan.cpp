
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        int len=pattern.length();
        vector<int> cpr=restruct(pattern);
        for(vector<string>::iterator it=words.begin();it!=words.end();it++){
            if(restruct(*it)==cpr) res.push_back(*it);
        }
        return res;
    }
    
    vector<int> restruct(string s) {
	    map<int, char>a;
	    vector<int>res;
	    int biggest = 0;
	    for (int i = 0; i<s.length(); i++) {
		    if (a.count(s[i])) res.push_back(a[s[i]]);
		    else {
			 a[s[i]] = biggest; res.push_back(a[s[i]]); biggest++;
		    }
	    }
	    return res;
    }
};
