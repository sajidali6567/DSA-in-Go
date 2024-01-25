class Solution {
public:
    int numOfSetBit(int n) {
        return __builtin_popcount(n);
    }
    int solve(vector<int> &bitArr, int index, int concatenatedSoFar) {
        if (index == bitArr.size()) return 0;
        
        int pick = 0;
        // check if current index can be picked
        if (numOfSetBit(bitArr[index] ^concatenatedSoFar) == numOfSetBit(bitArr[index]) + numOfSetBit(concatenatedSoFar) ) {
            pick = numOfSetBit(bitArr[index]) + solve(bitArr, index+1, concatenatedSoFar ^ bitArr[index]);
        }
        int notPick = solve(bitArr, index+1, concatenatedSoFar);
        return max(pick, notPick);
    }
    
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        // replace string array with int array where int has 26 bits and nth set bits represent 'a' + nth character is present in the string
        vector<int> bitArr(n, 0);
        for(int i=0;i<n;i++) {
            for(auto ch: arr[i]) {
                bitArr[i] ^= (1 << (ch-'a'));
            }
            // if string had duplicate characters it can't be picked so make it zero
            if(numOfSetBit(bitArr[i]) != arr[i].size()) {
                bitArr[i] = 0;
            }
        }
        return solve(bitArr, 0, 0);
    }
};