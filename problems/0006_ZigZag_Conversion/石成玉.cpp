class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1)
            return s;
        string result = "";
        int lens = s.length();
        int lenZ = 2 * numRows - 2;
        int numZ = lens / lenZ + 1;
        for (int i=0; i<numRows; i++) {
            for (int j=0; j<numZ; j++) {
                if (j*lenZ+i < lens)
                    result += s[j*lenZ+i];
                if (i!=0 && i!=numRows-1 && j*lenZ+lenZ-i<lens)
                    result += s[j*lenZ+lenZ-i];
            }
        }
        return result;
    }
};
