var parents [26]byte
func smallestEquivalentString(s1 string, s2 string, baseStr string) string {
    var i byte = 0
    for i = 0; i < 26; i++ {
        parents[i] = i;
    }
    
    byteS1 := []byte(s1)
    byteS2 := []byte(s2)
    for index, _ := range byteS1 {
        union(byteS1[index], byteS2[index])
    }
    byteBaseStr := []byte(baseStr)
    
    smallestEquivalentStringBytes := make([]byte, 0)
    for index, _ := range byteBaseStr {
        smallestEquivalentStringBytes = append(smallestEquivalentStringBytes, 'a' + find(byteBaseStr[index] - 'a'))
    }
    return string(smallestEquivalentStringBytes[:])
}

func union(a, b byte) {    
    pa := find(a-'a')
    pb := find(b-'a')
    if pa == pb {
        return
    }
    
    if pa <= pb {
        parents[pb] = pa
    } else {
        parents[pa] = pb
    }
}

func find(x byte) byte {
    if x == parents[x] {
        return x
    }
    parents[x] = find(parents[x]) // path compression
    return parents[x]
}