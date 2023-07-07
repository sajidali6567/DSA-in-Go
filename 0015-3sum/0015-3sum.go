func threeSum(nums []int) [][]int {
    sort.Ints(nums)
    var ans [][]int
    // Previous will store the previous value of i and j to avoid duplicates
    var prev_ij_array [][]int
    // This is a variation of two sum problem
    for k, _ := range nums {
        nums_ij_array := twoSum(nums, -nums[k], k+1, len(nums)-1)
        for _,  nums_ij := range nums_ij_array {
            // Checking if the same answer was found in previous step, do not add in answer
            if nums_ij != nil && !isPresentInPrevArray(prev_ij_array, nums_ij) {
                nums_ijk := append(nums_ij, nums[k])
                ans = append(ans, nums_ijk)
            }
        }
        prev_ij_array = nums_ij_array
    }
    return ans;
} 

// Checks if nums_ij is present in prev_ij_array
func isPresentInPrevArray(prev_ij_array [][]int, nums_ij []int) bool {
    for _, prev_ij := range prev_ij_array {
        if prev_ij[0] == nums_ij[0] && prev_ij[1] == nums_ij[1] {
            return true
        }
    }
    return false
}

func twoSum(numbers []int, target, start, end int) [][]int {
    prev := []int{int(1e5)+1, int(1e5)+1}
    var ans [][]int
    for start < end {
        sum := numbers[start] + numbers[end]
        if sum == target {
            current_ans := []int{numbers[start], numbers[end]}
            if prev[0] != current_ans[0] || prev[1] != current_ans[1] {
                ans = append(ans, current_ans)
            }
            prev = current_ans
            start++
            end--;
        } else if sum > target {
            end--
        } else {
            start++
        }
    }
    return ans
}