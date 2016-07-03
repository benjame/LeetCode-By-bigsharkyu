class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) 
            return "";
        int N = strs[0].size();
        int N2 = strs.size();
        for (int i = 0; i < N; ++i) {
            //这个循环控制第一个string的第i个字符
            for (int j = 1; j < N2; ++j) {
                //这个循环控制第j个string
                if (strs[0][i] != strs[j][i]) return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};