class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp; // maps element of nums2 to its original index
        vector<int> ogNums2(nums2.begin(), nums2.end()); // original nums2 array
        
        stack<int> st; // stores index of the array
        for(int i=0;i<nums2.size();i++) {
            mp[nums2[i]] = i;
            // update current index as next greater index for all the index at which elements are less than current element
            while(!st.empty() && nums2[i] > nums2[st.top()] ) {
                nums2[st.top()] = i;
                st.pop();
            }
            
            st.push(i);
        }
        
        // remaining elements of stack does not have any next greater element to push as -1
        while(!st.empty()) {
            nums2[st.top()] = -1;
            st.pop();
        }
        
        // index of the element in nums2 can be found using mp[num]
        // nums2 contains the index of next greater element
        // use original nums2 to find the next greater element using index found in the previous step
        vector<int> ans;
        for(auto num:nums1) {
            if(nums2[mp[num]] == -1) {
                ans.push_back(-1); continue;
            }
            ans.push_back(ogNums2[nums2[mp[num]]]);
        }
        
        return ans;
    }
};