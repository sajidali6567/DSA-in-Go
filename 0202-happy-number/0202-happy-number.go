func sSD(n int) int {
    result := 0;
    for n != 0 {
        lastDigit := n%10
        result += lastDigit * lastDigit
        n = n / 10
    }
    return result
}

func isHappy(n int) bool {
    mp := make(map[int]bool)
    for n !=1 {
        // Calculate sum of square of digits
        result := sSD(n)
        
        // Check if it already present in map
        if _, ok := mp[result]; ok {
            return false
        }
        
        // Push the calculated value in map
        mp[result] = true
        n = result
    }
    return true
}