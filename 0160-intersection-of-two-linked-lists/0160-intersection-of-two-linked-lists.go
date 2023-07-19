/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
import "math"
func getIntersectionNode(headA, headB *ListNode) *ListNode {
    countA := 0
    countB := 0
    listA, listB := headA, headB
    for listA != nil {
        listA = listA.Next
        countA++
    }
    
    for listB != nil {
        listB = listB.Next
        countB++
    }
    
    diff := int(math.Abs(float64(countB - countA)))
    listA, listB = headA, headB
    fmt.Println(diff)
    // move the node with greater value for diff times
    if countA > countB {
        // move listA for diff time
        for diff > 0 {
            listA = listA.Next
            diff--
        }
    } else if countB > countA {
        // move listB for diff time
        for diff > 0 {
            listB = listB.Next
            diff--
        }
    }
    // fmt.Println(listA.Val, listB.Val)
    fmt.Println(listA.Val, listB.Val)
    // Check where it meets
    for listA != nil && listB != nil {
        if listA == listB {
            return listB
        }
        listA = listA.Next
        listB = listB.Next
    }
    return nil
}