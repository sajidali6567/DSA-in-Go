// Observations:
// 1. Any number other than 1 can be written in combination of 2 and 3.
// 2. If we pick any number n (other than 1), either n, n-2, n-4 will be divisible by 3
// Approach 2:
// if we divide frequency by 3, we will get remainder as 0, 1, 2
// in case of 2, frequency/3 + 1 (pair of 2)
// in case of 1, take 3 out to make two pairs of 2
// frequency/3 - 1((pair of 3) + 2 (two pairs of 2) == frequency/3 + 1
func minOperations(nums []int) int {
    frequencyMap := make(map[int]int, 0)
    for _, num := range nums {
        frequencyMap[num]++;
    }
    minOpRequired := 0
    for _, frequency := range frequencyMap {
        if frequency == 1 {
            return -1
        }     
        switch frequency % 3 {
            case 0:
                minOpRequired += frequency/3
            default: // case 1 and 2
                minOpRequired += frequency/3 + 1
        }
    }
    return minOpRequired
}