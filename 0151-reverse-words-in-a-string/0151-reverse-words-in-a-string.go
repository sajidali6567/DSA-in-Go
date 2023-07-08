func reverseWords(s string) string {
    start := 0
    end := len(s) -1
    var front, back []byte
    
    for start <= end {
    
        // skip spaces before a word
        for start <= end && s[start] == ' ' {
            start++
        }
        // skip spaces after word
        for start <= end && s[end] == ' ' {
            end--
        }

        // pick the first word and add it to front of back string
        var leftWord, rightWord []byte
        for start <= end &&  s[start] != ' ' {
            leftWord = append(leftWord, s[start])
            start++
        }
        if leftWord != nil {
            leftWord = append([]byte{' '}, leftWord...)
            back = append(leftWord, back...)
        }
        // pick the word from right and append it to end of front string
        for start <= end &&  s[end] != ' ' {
            rightWord = append([]byte{s[end]}, rightWord...)
            end--
        }
        if rightWord != nil {
            rightWord = append(rightWord, ' ')
            front =  append(front, rightWord...)
        }
        
        start++
        end--
    }
    return string(append(front, back[1:]...))
}