class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stack;
        vector<int> ans;
        int n = temperatures.size();
        // start from end, and maintain the monotonic stack of maximum elements
        for(int i = n-1; i>=0; i--) {
            int temp = temperatures[i];
            while(!stack.empty() && temp >= temperatures[stack.top()]) {
                stack.pop();
            }
            if(stack.empty()) ans.push_back(0); else ans.push_back(stack.top() - i);
            stack.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};