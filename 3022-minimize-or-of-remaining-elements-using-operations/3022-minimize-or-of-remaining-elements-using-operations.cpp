class Solution {
public:
    int ALLONES = ((1ll << 31) - 1);
    void print(vector<int>& bits) {
        for(auto bit:bits) {
            cout << bit << " ";
        } cout << endl;
    }
    
    bool isAllBitsZero(int andSoFar, vector<int>& bits) {
        for(auto bit:bits) {
            int mask = 1 << bit;
            // cout << "mask " << mask << endl;
            // check if bit is zero in ansSoFar
            if( (andSoFar & mask) != 0) {
                return false;
            }
        }
        return true;
    }
    
    // calculate number of operations it takes to make all the bit present in bits as zero
    // This uses the idea that if we have made MSB as zero then while making the next less significant bits as zero
    // we need to make sure the earlier chosen bits are also made to zero
    int caculateOperation(vector<int>& bits, vector<int>& nums) {
        // print(bits);
        int i=0, numOfPartition = 0, n = nums.size();
        int andSoFar = ALLONES; // initialization
        while(i < n) {
            andSoFar &= nums[i];
            // cout << "andSoFar = " << andSoFar << endl;
            // if andSoFar has all the bit in bits as zero, this is a partition (these nums needs to be taken together, in order to make all the bit of bits as zero)
            // cout << "isAllBitsZero(andSoFar, bits) " << isAllBitsZero(andSoFar, bits) << endl;
            if(isAllBitsZero(andSoFar, bits)) {
                numOfPartition++;
                andSoFar = ALLONES; // reset andSoFar for the next partition
            }
            i++;
        }
        // cout << "numOfPartition = " << numOfPartition << endl;
        return (n - numOfPartition);
    }
    
    int minOrAfterOperations(vector<int>& nums, int k) {
        // vector<int> a = {3};
        // cout << isAllBitsZero(8, a) << endl;
        
        // to make or of the array minimum, we will greedily try to make bits as zero, starting from MSB
        vector<int> bits; // keeps track of the bits which can be made zero within k operation
        
        for(int bit = 30; bit>=0 ; bit--) {
            // assume bit can be made zero
            bits.push_back(bit);
            int x = caculateOperation(bits, nums);
            // cout << "bit " << bit << " is taking " << x << " operation to become zero\n";
            // if it is taking more than k operation, then it can not be made zero, pop from bits
            if(x > k) {
                bits.pop_back();
            }
        }
        
        // print(bits);
        
        // Construct the answer, by taking a 31 bit number, and making all the bit from bits as zero
        int ans = ALLONES;
        for(auto bit:bits) {
            // unset bit
            ans = (ans ^ (1 << bit));
        }
        return ans;
    }
};