/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
   (Number(l1.reverse().join(''))+Number(l2.reverse().join(''))).toString().split('').reverse().join('->')
};
addTwoNumbers([2,4,3],[5,6,4]);
