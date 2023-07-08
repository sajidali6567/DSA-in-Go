func reverseWords(s string) string {
    end := len(s) -1
    var ans []byte
    
    for end >= 0 {
    
        // skip spaces before word
        for end >= 0 && s[end] == ' ' {
            end--
        }

        // pick the current work from the back and add it to the ans
        var current_word []byte
        for end >= 0 &&  s[end] != ' ' {
            current_word = append([]byte{s[end]}, current_word...)
            end--
        }
        if current_word != nil {
            current_word = append(current_word, ' ')
            ans =  append(ans, current_word...)
        }
        end--
    }
    return string(ans[:len(ans)-1])
}