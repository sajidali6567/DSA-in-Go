// This function returns |a - b|
func Abs(a, b int) int {
    if a > b {
        return a -b
    }
    return b-a
}

func findOccurenceOfPattern(pattern, text string) []int {
    n := len(pattern)
    m := len(text)
    ans := make([]int, 0) // stores all the index where pattern is found in the text
    combinedStr := pattern + "#" + text
    // pi is the prefix function for pattern + '#' + text
    // pi[0] and pi[n] will be zero
    var pi []int = make([]int, n+m+1)
    for i := 1; i < n + m + 1; i++ {
        j := pi[i-1]
        // find the maximum j for which prefix function property holds at index i
        for j > 0 && combinedStr[j] != combinedStr[i] {
            j = pi[j-1]
        }
        // After finding the length j, check if 
        if combinedStr[i] == combinedStr[j] {
            j++
        }
        pi[i] = j
        // Check if pattern is found
        if pi[i] == n {
            // (i -n + 1) is index in combinedStr
            // we need to subtract (n+1) to find the index in text
            ans = append(ans, (i -n + 1) - (n+1) )
        }
    }  
    return ans
}

func beautifulIndices(s string, a string, b string, k int) []int {
    aIndices := findOccurenceOfPattern(a, s)
    bIndices := findOccurenceOfPattern(b, s)
    fmt.Println(aIndices)
    fmt.Println(bIndices)
    
    // Find the indices of a which are in b and at most k distance apart
    // Using two pointers approach keeping in mind that, indices are in sorted order
    // so if any element in a are 
    i, j := 0, 0
    ans := make([]int, 0)
    for i < len(aIndices) {
        for j < len(bIndices) && bIndices[j] <= aIndices[i] + k {
            if Abs(bIndices[j], aIndices[i]) <= k {
                break
            }
            j++
        }
        if j == len(bIndices) {
            break;
        }
        if Abs(bIndices[j], aIndices[i]) <= k {
            ans = append(ans, aIndices[i])
        } 
        i++
    }
    return ans
}