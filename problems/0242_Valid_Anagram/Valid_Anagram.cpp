class Solution {
public:
    bool isAnagram(string s, string t) {
        int alp1[26]{0},alp2[26]{0};
        for(auto ch:s)
            alp1[ch-'a']++;
        for(auto ch:t)
            alp2[ch-'a']++;
        return equal(cbegin(alp1),cend(alp1),cbegin(alp2));
    }
};