class Solution {
public:
    typedef unsigned long long ll;
    ll check(long long n, int x) {
        ll rows = n + 1;
        ll countOfOnes = 0;
        ll i = x;
        while(i <= log2(n) + 1) {
            ll toggle = 1ll << (i-1); // in column i bits toggle after every pow(2, i-1) row
            ll blockSize = 1ll << (i); // block where half of the numbers i.e. pow(2, i-1) is zero and other half is one
            ll numberOfBlocks = rows / blockSize; // number of blocks which can be made
            countOfOnes += numberOfBlocks * toggle;
            ll remainderBlockSize = rows % blockSize;
            countOfOnes += (remainderBlockSize > toggle)?remainderBlockSize - toggle:0;
            i += x; // after i, i+xth bit will be divisible by x
        }
        return countOfOnes;
    }
    long long findMaximumNumber(long long k, int x) {
        long long low = 1, high = 1e15;
        while(low <= high) {
            long long mid = low + ((high- low) / 2);
            if((check(mid, x) <= k)) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return high;
    }
};