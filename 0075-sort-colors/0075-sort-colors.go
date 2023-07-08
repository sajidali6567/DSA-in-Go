func sortColors(nums []int)  {
    // We will use three pointers
    // i will point to the position of next zero
    // j will point to the position of next two
    // k will keep moving and swapping 0 and 2 to tha first and last of array
    i, j, k := 0, len(nums)-1, 0
    for k <= j {
        switch nums[k] {
        case 0:
            nums[i], nums[k] = nums[k], nums[i]
            i++
            k++
        case 1:
            k++;
        case 2:
            nums[k], nums[j] = nums[j], nums[k]
            j--
        }
    }
}

// func swap(nums []int, i, j int) {
//     nums[i], nums[j] = nums[j], nums[i]
// }