class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums2) {
        map<int, int> mp; // maps element of nums2 to its original index
        vector<int> nextGreaterElem(nums2.size(), -1); // remaining elements of stack does not have any next greater element so initialing all of them as -1
        
        
        stack<int> st; // stores index of the array
        for(int i=0;i<nextGreaterElem.size();i++) {
            mp[nums2[i]] = i;
            // update current index as next greater index for all the index at which elements are less than current element
            while(!st.empty() && nums2[i] > nums2[st.top()] ) {
                nextGreaterElem[st.top()] = nums2[i];
                st.pop();
            }
            
            st.push(i);
        }
        
        for(int i=0;i<nextGreaterElem.size();i++) {
            mp[nums2[i]] = i;
            // update current index as next greater index for all the index at which elements are less than current element
            while(!st.empty() && nums2[i] > nums2[st.top()] ) {
                nextGreaterElem[st.top()] = nums2[i];
                st.pop();
            }
            
            st.push(i);
        }
        
        return nextGreaterElem;
    }
};