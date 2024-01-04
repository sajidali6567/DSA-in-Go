func minOperations(nums []int) int {
    frequencyMap := make(map[int]int, 0)
    for _, num := range nums {
        frequencyMap[num]++;
    }
    minOpRequired := 0
    for _, frequency := range frequencyMap {
        switch {
            case frequency == 1:
                return -1
            case frequency % 3 == 0:
                minOpRequired += frequency/3
            case (frequency - 2) % 3 == 0:
                minOpRequired += (frequency - 2) / 3 + 1
            case (frequency - 4) % 3 == 0:
                minOpRequired += (frequency -4) / 3 + 2
        }
    }
    return minOpRequired
}