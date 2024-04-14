class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        map<int, int> mp; // maps element of nums2 to its original index
        int n = nums.size();
        vector<int> nextGreaterElem(n, -1); // remaining elements of stack does not have any next greater element so initialing all of them as -1
        stack<int> st; // stores index of the array
        // run the next greater element I code two time
        for(int i=0;i< 2*n -1 ;i++) {
            mp[nums[i%n]] = i%n;
            // update current index as next greater index for all the index at which elements are less than current element
            while(!st.empty() && nums[i%n] > nums[st.top()] ) {
                nextGreaterElem[st.top()] = nums[i%n];
                st.pop();
            }
            st.push(i%n);
        }
        
        return nextGreaterElem;
    }
};