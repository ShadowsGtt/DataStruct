package main

import "fmt"

// AdjustHeap 调整堆结构
func AdjustHeap(nums []int, rootIdx int, size int, sortFn func(i, j int) bool) {
	for {
		selectedIdx := rootIdx
		leftIdx := rootIdx*2 + 1
		rightIdx := rootIdx*2 + 2
		if rightIdx < size && sortFn(nums[rightIdx], nums[selectedIdx]) {
			selectedIdx = rightIdx
		}
		if leftIdx < size && sortFn(nums[leftIdx], nums[selectedIdx]) {
			selectedIdx = leftIdx
		}
		// 不需要调整 则直接退出
		if selectedIdx == rootIdx {
			break
		}
		// 需要调整 则将数值较大的节点调整至根位置
		nums[rootIdx], nums[selectedIdx] = nums[selectedIdx], nums[rootIdx]
		// 调整后,破坏了的堆结构,需要从受到影响的一边继续向下调整
		rootIdx = selectedIdx
	}
}

func HeapSort(nums []int) {
	// 建立初始堆: 从最后一个根节点开始向上建立,将每个小堆(3节点)都建立成大顶堆
	size := len(nums)
	for rootIdx := size/2 - 1; rootIdx >= 0; rootIdx-- {
		AdjustHeap(nums, rootIdx, size, func(i, j int) bool {
			return i > j
		})
	}
	// 调整完之后,最大的元素在堆顶(下标=0),将堆顶元素放到最后(为了方便从后续调整)
	for i := size - 1; i > 0; i-- {
		nums[0], nums[i] = nums[i], nums[0]
		AdjustHeap(nums, 0, i, func(i, j int) bool {
			return i > j
		})
	}
}

// TopK 查找top k
func TopK(nums []int, k int) []int {
	if len(nums) <= k {
		return nums
	}
	heapArr := nums[:k]
	cmp := func(i, j int) bool {
		return i < j
	}
	// 建立初始堆
	for rootIdx := len(heapArr)/2 - 1; rootIdx >= 0; rootIdx-- {
		AdjustHeap(heapArr, rootIdx, len(heapArr), cmp)
	}
	fmt.Println("初始小顶堆: ", heapArr)
	for i := k + 1; i < len(nums); i++ {
		// 当前数 > 堆顶, 替换堆顶最小元素
		if nums[i] > heapArr[0] {
			fmt.Println("当前元素:", nums[i])

			fmt.Println("替换堆顶前:  ", heapArr)
			heapArr[0] = nums[i]
			fmt.Println("替换堆顶后: ", heapArr)
			for rootIdx := len(heapArr)/2 - 1; rootIdx >= 0; rootIdx-- {
				AdjustHeap(heapArr, rootIdx, len(heapArr), cmp)
			}
			fmt.Println("堆调整之后: ", heapArr)
			fmt.Println()
		}
	}

	return heapArr
}

func main() {
	nums := []int{3, 8, 4, 2, 1, 7, 0, 6, 4, 21, 32, 12, 22, 5, 77, 77, 77, 24, 47, 87}
	// HeapSort(nums)
	// fmt.Println(nums)
	fmt.Println("TopK: ", TopK(nums, 5))
}
