class Solution {
public:    
    int ALLONES = ((1ll << 31) - 1);
    bool isAllBitsZero(int andSoFar, int mask) {
        return ( (andSoFar & mask) == 0);
    }
    
    // calculate number of operations it takes to make all the set bit in mask as zero
    // This uses the idea that if we have made MSB as zero then while making the next less significant bits as zero
    // we need to make sure the earlier chosen bits are also made to zero
    int calculateOperation(int mask, vector<int>& nums) {
        int i=0, numOfPartition = 0, n = nums.size();
        int andSoFar = ALLONES; // initialization as we x & 1 = x
        while(i < n) {
            andSoFar &= nums[i];
            // if andSoFar can make set bits of mask as zero, this is a partition
            if(isAllBitsZero(andSoFar, mask)) {
                numOfPartition++;
                andSoFar = ALLONES; // reset andSoFar for the next partition
            }
            i++;
        }
        return (n - numOfPartition);
    }
    
    int minOrAfterOperations(vector<int>& nums, int k) {       
        // to make or of the array minimum, we will greedily try to make bits as zero, starting from MSB
        int mask = 0; // keeps track of the bits which can be made zero within k operation
        
        for(int bit = 30; bit>=0 ; bit--) {
            // assume bit can be made zero
            mask |= (1ll << bit);
            int x = calculateOperation(mask, nums);
            
            // if it is taking more than k operation, then it can not be made zero, unset this particular bit from mask
            if(x > k) {
                mask &= ~(1ll << bit); // 0 at the bit and rest 1s
            }
        }
        // Construct the answer, 1 in mask represent that particular bit can be made zero and 0 represents it can not
        // taking XOR with all ones will flip bits of the mask
        return ALLONES ^ mask;
    }
};