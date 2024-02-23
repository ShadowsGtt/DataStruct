package main

import "fmt"

func AtoI(str string) (int, error) {
	if len(str) == 0 {
		return 0, fmt.Errorf("invalid number string")
	}
	s0 := str[0]
	flag := 1
	if s0 == '-' {
		str = str[1:]
		flag = -1
	} else if s0 == '+' {
		str = str[1:]
	}

	num := 0
	for _, s := range str {
		if s > '9' || s < '0' {
			return 0, fmt.Errorf("unexpect char")
		}
		s -= '0'
		num = num*10 + int(s)
	}

	return flag * num, nil
}

func main() {
	fmt.Println(AtoI("-123"))
	fmt.Println(AtoI("+222"))
	fmt.Println(AtoI("0"))
	fmt.Println(AtoI("1"))
	fmt.Println(AtoI(""))
	fmt.Println(AtoI("1cavb"))
}
