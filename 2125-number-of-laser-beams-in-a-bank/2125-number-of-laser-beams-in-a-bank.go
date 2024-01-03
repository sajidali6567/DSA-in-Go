func numberOfBeams(banks []string) int {
    // prev represents the count of devices in previous row with non zero devices
    prevRowDeviceCount := 0
    ans := 0      
    for _, bank := range banks {
        if !strings.Contains(bank, "1") {
            continue
        }
        
        currentRowDeviceCount := countOnes(bank)
        ans += prevRowDeviceCount * currentRowDeviceCount
        prevRowDeviceCount = currentRowDeviceCount
    }
    return ans
}

func countOnes(bank string) int {
    currentRowDeviceCount := 0
    for _, ch := range bank {
        if(ch == '1') {
            currentRowDeviceCount++
        }
    }
    return currentRowDeviceCount
}