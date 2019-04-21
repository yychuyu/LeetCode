// O(1) 常量时间, 考虑一个存值的数组， 一个Left, Right数字代表左右子数
// 先用双向链表实现吧
package LRUCache

type LRUCache struct {
	Size   int
	Length int
	Head   *Node
	Tail   *Node
	Nodess map[int]*Node
}

type Node struct {
	Key, Value int
	Left       *Node
	Right      *Node
}

func Constructor(capacity int) LRUCache {
	return LRUCache{Size: capacity, Length: 0, Head: nil, Tail: nil, Nodess: make(map[int]*Node)}
}

func (this *LRUCache) Get(key int) int {
	if this.Head == nil {
		this.Nodess[key] = nil
		return -1
	}
	if res, _ := this.Nodess[key]; res != nil {
		if res.Left == nil {
			return res.Value
		}
		if res.Right != nil {
			res.Left.Right = res.Right
			res.Right.Left = res.Left
		} else {
			this.Tail = this.Tail.Left
			this.Tail.Right = nil
		}
		res.Right = this.Head
		this.Head.Left = res
		this.Head = res
		this.Head.Left = nil
		return res.Value
	}
	return -1
}

func (this *LRUCache) Put(key int, value int) {
	if res := this.Get(key); res != -1{
		// key是存在的, 更新key
		this.Nodess[key].Value = value
		return
	}
	node := &Node{key, value, nil, nil}
	if this.Length < this.Size {
		if this.Head == nil {
			this.Head = node
			this.Tail = node
		} else {
			node.Right = this.Head
			this.Head.Left = node
			this.Head = node
		}
		this.Length++
	} else {
		node.Right = this.Head
		this.Head.Left = node
		this.Head = node
		delete(this.Nodess, this.Tail.Key)
		this.Tail = this.Tail.Left
		this.Tail.Right = nil
	}
	this.Nodess[key] = node
}
