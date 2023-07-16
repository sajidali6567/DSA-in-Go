func minimumIndex(nums []int) int {
    n := len(nums)
    mp := make(map[int]int, 0)
    dominant := 0
    // Step 1: find the dominant element and its count
    for i := 0; i <n; i++ {
        mp[nums[i]] = mp[nums[i]] + 1
        if 2 * mp[nums[i]] > n {
            dominant = nums[i]
        }
    }
    
    // Step 2: Traverse the array and keep the count of dominant in first subarray
    // return the first point where both subarray satisfies the condition
    countOfDominant := 0
    for i := 0; i <n; i++ {
        if nums[i] == dominant {
            countOfDominant++
            lengthOfCurrentSubarray := i +1
            lengthOfRemainingSubarray := n - i - 1
            remainingDominantCount := mp[dominant] - countOfDominant
            if 2 * countOfDominant > lengthOfCurrentSubarray && 2 * remainingDominantCount > lengthOfRemainingSubarray  {
                return i
            }
        }           
    }
    return -1
}