class Solution {
public:
    
    void nge1(map<int, int>& mp, vector<int>& nextGreaterElem, stack<int>& st, vector<int>& nums) {
        for(int i=0;i<nextGreaterElem.size();i++) {
            mp[nums[i]] = i;
            // update current index as next greater index for all the index at which elements are less than current element
            while(!st.empty() && nums[i] > nums[st.top()] ) {
                nextGreaterElem[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
    }
    
    vector<int> nextGreaterElements(vector<int>& nums) {
        map<int, int> mp; // maps element of nums2 to its original index
        vector<int> nextGreaterElem(nums.size(), -1); // remaining elements of stack does not have any next greater element so initialing all of them as -1
        stack<int> st; // stores index of the array
        // run the next greater element I code two time
        nge1(mp, nextGreaterElem, st, nums);
        nge1(mp, nextGreaterElem, st, nums);
        
        return nextGreaterElem;
    }
};