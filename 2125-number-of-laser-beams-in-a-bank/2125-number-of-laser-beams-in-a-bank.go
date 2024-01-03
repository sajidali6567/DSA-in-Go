func numberOfBeams(banks []string) int {
    // prev represents the count of devices in previous row with non zero devices
    prevRowDeviceCount := 0
    ans := 0      
    for _, bank := range banks {
        currentRowDeviceCount := 0
        for _, ch := range bank {
            if(ch == '1') {
                currentRowDeviceCount++
            }
        }

        if currentRowDeviceCount == 0 {
            continue
        }
        ans += prevRowDeviceCount * currentRowDeviceCount
        prevRowDeviceCount = currentRowDeviceCount
    }
    return ans
}