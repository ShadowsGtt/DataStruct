package main

import (
	"fmt"
)

// MaxNonRepeatedSubStr 最长无重复子串
func MaxNonRepeatedSubStr(str string) int {
	// 字符串长度
	sLen := len(str)
	if sLen <= 1 {
		return sLen
	}
	maxLen := 0 // 最大长度
	right := 0  // 左指针
	left := 0   // 右指针

	// 用hash map的方式记录子串, 为了方便判断某个字符是否已经在子串中出现过
	subStrMap := map[byte]struct{}{}
	// 循环终止条件是左右指针都不越界
	for left < sLen && right < sLen {
		// 右指针对应字符没有在sub str中出现
		if _, ok := subStrMap[str[right]]; !ok {
			// 计算sub str长度
			curLen := right - left + 1
			// 当前sub str长度超过上次最大长度 则更新sub str最大长度
			if curLen > maxLen {
				maxLen = curLen
			}
			// 新字符记录到sub str
			subStrMap[str[right]] = struct{}{}
			// 移动右指针
			right++
		} else {
			// 右指针所指字符出现在sub str中, 则需要左指针移动
			// 左指针移动需要将左指针外的字符从sub str中先删除
			delete(subStrMap, str[left])
			left++
		}
	}
	return maxLen
}

func lengthOfLongestSubstring(s string) int {
	// 哈希集合，记录每个字符是否出现过
	m := map[byte]int{}
	n := len(s)
	// 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
	rk, ans := 0, 0
	for i := 0; i < n; i++ {
		fmt.Println(fmt.Sprintf("left = s[%d] = %c", i, s[i]))
		if i != 0 {
			// 左指针向右移动一格，移除一个字符
			delete(m, s[i-1])
			fmt.Println(fmt.Sprintf("删除: s[%d] = %c", i-1, s[i-1]))
		}
		for rk < n && m[s[rk]] == 0 {
			fmt.Println(fmt.Sprintf("right: s[%d] = %c", rk, s[rk]))
			// 不断地移动右指针
			m[s[rk]]++
			rk++
		}
		// 第 i 到 rk 个字符是一个极长的无重复字符子串
		ans = max(ans, rk-i)
	}
	return ans
}

func main() {
	fmt.Println(MaxNonRepeatedSubStr("abcdc"))
}
