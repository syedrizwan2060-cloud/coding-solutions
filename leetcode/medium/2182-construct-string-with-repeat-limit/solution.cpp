
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {

        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string result;

        int i = 25;

        while (i >= 0) {

            if (freq[i] == 0) {
                i--;
                continue;
            }

            int use = min(freq[i], repeatLimit);

            result.append(use, char('a' + i));
            freq[i] -= use;

            if (freq[i] == 0) {
                continue;
            }

            int j = i - 1;

            while (j >= 0 && freq[j] == 0) {
                j--;
            }

            if (j < 0) {
                break;
            }

            result.push_back(char('a' + j));
            freq[j]--;
        }

        return result;
    }
};
