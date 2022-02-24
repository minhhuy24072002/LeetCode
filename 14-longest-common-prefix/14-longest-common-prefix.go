func longestCommonPrefix(strs []string) string {
    var res string = ""
    canIterate := true
    for i := 0; canIterate && i < len(strs[0]); i++ {
        for j := 0; j < len(strs); j++ {
            if (i >= len(strs[j]) || strs[0][i] != strs[j][i]) {
                //fmt.Println(i, j)
                canIterate = false
                break
            }
        }
        if (canIterate) {
            res = res + string(strs[0][i])
        }
    }
    
    return res
}