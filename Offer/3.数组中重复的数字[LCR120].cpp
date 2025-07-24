class Solution {
public:
    int findRepeatDocument(vector<int>& documents) {
        // 重点：长度为 n 的数组中所有数字都在 0~n-1 范围内
        int i=0;
        for (; i<documents.size(); ++i) {
            while (i != documents[i]) {
                if (documents[i] == documents[documents[i]]) break;
                std::swap(documents[i], documents[documents[i]]);
            }
            if (i != documents[i] && documents[i] == documents[documents[i]]) break;
        }
        return documents[i];
    }
};