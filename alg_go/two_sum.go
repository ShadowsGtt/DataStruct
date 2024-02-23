package main

import "fmt"

func TwoSum(arr []int, target int) []int {
	hash := map[int]int{}
	for idx, i := range arr {
		if v, ok := hash[target-i]; ok {
			return []int{v, idx}
		}
		hash[i] = idx
	}

	return nil
}

func main() {
	arr := []int{2, 4, 7, 0, 9, 1}
	fmt.Println(TwoSum(arr, 10))
}
