package main

import "fmt"

func naive_even(n int) bool {
	return n % 2 == 0
}

func fast_even(n int) bool {
	return n & 1 == 0
}

func main() {
	fmt.Println(naive_even(3))
	fmt.Println(fast_even(44))
}
