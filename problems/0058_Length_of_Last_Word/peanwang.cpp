class Solution {
public:
    int lengthOfLastWord(string s) {
	    int len = 0;
	    auto it = s.rbegin();
	    while (it != s.rend()) {
		    if (*it == ' ')
			    it++;
	    	else
		    	break;
	    }
	    for (; it != s.rend(); it++) {
		    if (*it != ' ')
			    len++;
	    	else
		    	break;
	    }
	    return len;
    }
};