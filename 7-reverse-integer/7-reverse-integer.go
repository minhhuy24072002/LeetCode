
func reverse(x int) int {
    isNegative := x < 0
    temp := x
    
    if isNegative {
        temp = -temp
    }
    
    reversedX := 0
    
    for temp > 0 {
        reversedX = reversedX * 10 + (temp % 10)
        temp /= 10
    }
    
    if isNegative {
        reversedX = -reversedX
    }
    
    if reversedX > math.MaxInt32 || math.MinInt32 > reversedX {
        return 0
    } else {
        return reversedX
    }
}