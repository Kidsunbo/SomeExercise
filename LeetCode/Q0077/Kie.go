package main

import "fmt"

func dfs(result *[][]int, item *[]int, depth int, n int, k int){
	if len(*item) == k{
		newItem := append([]int(nil), *item...)
		*result = append(*result, newItem)
		return
	}

	for i:= depth;i<n;i++{
		*item = append(*item, i+1)
		dfs(result, item, i+1, n,k)
		*item = (*item)[:len(*item)-1]
	}
}

func combine(n int, k int) [][]int {
	result := make([][]int, 0)
	item := make([]int, 0, k)
	dfs(&result, &item, 0, n,k)
	return result
}


func main() {
	fmt.Println(combine(4,2))
}