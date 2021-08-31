package main

import (
	"fmt"
	"strings"
)


func simplifyPath(path string) string {
	_paths :=strings.Split(path,"/")
	var paths []string
	for _,i := range _paths{
		if i==""||i=="."{
			continue
		}
		paths = append(paths,i)

	}

	var result []string
	for _,i :=range paths{
		if i==".." {
			if len(result) >= 1 {
				result = result[:len(result)-1]
			}
		} else{
			result = append(result,i)
		}
	}


	return "/"+strings.Join(result,"/")
}


func main(){

	fmt.Println(simplifyPath("//.."))


}


