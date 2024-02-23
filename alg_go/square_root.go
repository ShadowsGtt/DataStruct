package main

import (
	"fmt"
	"strconv"
)

func fn(n, e float32) float32 {
	// 先求 e 的精度
	d := fmt.Sprintf("%+v", e)
	length := len(d) - 2
	x := float32(0)
	if n > 0 && e > 0 {
		low := float32(0)
		high := n
		for low < high {
			// 二分，并控制精度
			ft := "%." + fmt.Sprintf("%d", length) + "f"
			v := fmt.Sprintf(ft, (low+high)/2)
			midF, _ := strconv.ParseFloat(v, 32)
			mid := float32(midF)
			if mid*mid < n-e {
				low = mid
			} else if mid*mid > n+e {
				high = mid
			} else {
				x = mid
				break
			}
		}

		return x

	}

	return x
}

func main() {
	fmt.Println(fn(0.04, 0.0001))

}
