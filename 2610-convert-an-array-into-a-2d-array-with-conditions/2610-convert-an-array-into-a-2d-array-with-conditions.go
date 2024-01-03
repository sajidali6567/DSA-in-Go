func max(a, b int) int {
    if(a > b) {
        return a
    }
    return b
}

func findMatrix(nums []int) [][]int {
    // create an array of size len(num) + 1
    frequencyArray := make([]int, len(nums)+1)

    // store the frquency of element in frequencyArray
    max_frequency := 0
    for _, num := range nums {
        frequencyArray[num]++
        max_frequency = max(max_frequency, frequencyArray[num])
    }
    
    var ans [][]int
    for i := 0; i < max_frequency; i++ {
        var rowArray []int
        for index, frequency := range frequencyArray {
            if(frequency > 0) {
                frequencyArray[index]--
                rowArray = append(rowArray, index)
            }
        }
        ans = append(ans, rowArray)
    }
    return ans
}