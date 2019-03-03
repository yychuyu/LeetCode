package main

import "fmt"

// 有兩個連結陣列分別代表兩個非負整數，他們的位數是反向儲存(越前面的節點位數越低)
// 毎一個節點代表一個位數，將這兩個連結陣列加總後以連結陣列形式回傳。
// 範例：
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 個位數為2與5，相加為7 ； 十位數為4+6 = 10，需要進位 ； 百位數為3 + 4 + 1(進位) = 8，結果為 7->0->8

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func main() {
	Num := [3]int{2, 4, 3}
	Num2 := [3]int{5, 6, 4}
	l1 := new(ListNode)
	l2 := new(ListNode)
	for i := 0; i < len(Num); i++ { //初始化
		if i == 0 {
			l1.Val = Num[i]
			l2.Val = Num2[i]
			//l1.Next = new(ListNode)
			fmt.Println("l1.Val =", l1.Val)
			fmt.Println("l2.Val =", l2.Val)
		} else {
			next := new(ListNode)
			next.Val = Num[i]
			l1.Next = next
			next2 := new(ListNode)
			next2.Val = Num2[i]
			l2.Next = next2
			fmt.Println("l1.Next =", l1.Next)
			fmt.Println("l2.Next =", l2.Next)
		}
		fmt.Println(addTwoNumbers(l1, l2))
	}
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	head := &ListNode{0, nil}
	current := head
	carry := 0
	for l1 != nil || l2 != nil || carry > 0 {
		sum := carry
		if l1 != nil {
			sum += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			sum += l2.Val
			l2 = l2.Next
		}
		carry = sum / 10
		current.Next = new(ListNode)
		current.Next.Val = sum % 10
		current = current.Next
	}
	return head.Next
}
