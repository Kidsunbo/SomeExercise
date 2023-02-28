package main

import (
	"fmt"
	"sort"
)

func dfs(nums []int, result *[][]int, curIdx int, subset []int) {
	var last *int
	for i := curIdx; i < len(nums); i++ {
		if i == curIdx || last != nil && *last != nums[i] {
			subset = append(subset, nums[i])
			*result = append(*result, append([]int{}, subset...))
			last = &nums[i]
			dfs(nums, result, i+1, subset)
			subset = subset[:len(subset)-1]
		}
	}
}

func subsetsWithDup(nums []int) [][]int {
	sort.Ints(nums)
	result := [][]int{{}}
	var subset []int
	dfs(nums, &result, 0, subset)
	return result
}

func main() {
	nums := []int{1, 1, 2, 2, 3, 3}
	fmt.Println(subsetsWithDup(nums))
}
