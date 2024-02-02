class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1;i<=9;i++) {
            int currentValue = i; // generates all the numbers whose digits are sequential and start from i
            int nextDigit = i + 1;
            while(nextDigit <= 9) {
                currentValue = currentValue * 10 + nextDigit; nextDigit++;
                if(currentValue > high) break;
                if(currentValue >= low) ans.push_back(currentValue);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};