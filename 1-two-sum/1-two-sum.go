func twoSum(nums []int, target int) []int {
    var res []int
    
    numIndex := make(map[int]int)
    
    for i := 0; i < len(nums); i++ {
        numIndex[nums[i]] = i;
    }
    
    for i := 0; i < len(nums); i++ {
        if _, isExist := numIndex[target - nums[i]]; isExist && numIndex[target - nums[i]] != i {
            res = append(res, i, numIndex[target - nums[i]])
            break
        }
    }
    
    return res
}