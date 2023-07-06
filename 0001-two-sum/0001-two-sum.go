func twoSum(nums []int, target int) []int {
    mp := make(map[int]int)
    for i := 0; i < len(nums); i++ {
        // Check if target - nums[i] is present in map, if yes then answer, else add current element and its index to map
        if j, ok := mp[target - nums[i]]; ok {
            return []int{i, j}
        }
        mp[nums[i]] = i
    }
    return nil
}