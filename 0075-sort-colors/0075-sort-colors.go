func sortColors(nums []int)  {
    // We will use three pointers
    // i will point to the position of next zero
    // j will point to the position of next two
    // k will keep moving and swapping 0 and 2 to tha first and last of array
    i, j, k := 0, len(nums)-1, 0
    swap := func(i, j int) {
        nums[i], nums[j] = nums[j], nums[i]
    }
    for k <= j {
        switch nums[k] {
        case 0:
            swap(i, k)
            i++
            k++
        case 1:
            k++;
        case 2:
            swap(j, k)
            j--
        }
    }
}