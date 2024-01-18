used KMP to find indices of string a and string b in S.
once indices are found used two pointers to find the an element in b correspoding to an element a.
Approach 1: Two pointers
We are using the fact that both the array are sorted.
Logic is for an element in array a. We will keep moving j untill we find the suitable b, or it goes beyond range of element + k.
Time Complexity: KMP O(len(s) + max(len(a), len(b)) + O(len(a))
​
Approach 2: Binary Search
​
Time Complexity: KMP O(len(s) + max(len(a), len(b)) + O(len(a) * len(b))