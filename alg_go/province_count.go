package main

import "fmt"

// GetProvinceCount 省份数量
func GetProvinceCount(arr [][]int) int {
	n := len(arr)
	visited := make([]bool, n)

	provinceCnt := 0
	queue := []int{}
	// 遍历所有城市
	for city := 0; city < n; city++ {
		// 当前城市没有访问过
		if !visited[city] {
			provinceCnt++
			queue = append(queue, city)
			// bfs所有相邻城市
			for len(queue) > 0 {
				curCity := queue[0]
				queue = queue[1:]
				visited[curCity] = true
				// 找到当前城市的所有相邻城市
				for dstCity, isConnect := range arr[city] {
					// 相邻 & 没有访问过
					if isConnect == 1 && !visited[dstCity] {
						queue = append(queue, dstCity)
					}
				}
			}
		}
	}

	return provinceCnt
}

// GetProvinceCount 省份数量
func GetProvinceCount2(arr [][]int) int {
	cnt := 0
	queue := []int{}
	visited := make([]bool, len(arr))
	for city := 0; city < len(arr); city++ {
		// 当前城市未访问
		if !visited[city] {
			cnt++
			queue = append(queue, city)
			// bfs遍历
			for len(queue) > 0 {
				curCity := queue[0]
				queue = queue[1:]
				visited[curCity] = true
				// 访问当前城市的相邻
				for c, conn := range arr[curCity] {
					if conn == 1 && !visited[c] {
						queue = append(queue, conn)
					}
				}
			}
		}
	}

	return cnt
}

func main() {
	//
	citys := [][]int{
		{1, 1, 0},
		{1, 1, 0},
		{0, 0, 1},
	}
	fmt.Println(GetProvinceCount(citys))

	// [1,0,0],[0,1,0],[0,0,1
	citys = [][]int{
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1},
	}
	fmt.Println(GetProvinceCount(citys))
}
