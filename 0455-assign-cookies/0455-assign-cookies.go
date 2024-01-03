func findContentChildren(g []int, s []int) int {
    sort.Ints(g)
    sort.Ints(s)
    i, j, ans := 0, 0, 0
    
    for i < len(g) && j < len(s) {
        // skip the cookies which can not be assigned to any children
        for j < len(s) && s[j] < g[i] {
            j++
        }
        // if cookie index went out of the range
        if(j >= len(s)) {
            break
        }
        // jth cookie can be assigned to ith child
        ans++
        i++
        j++
    }
    return ans;
}