public class ListNode {
    //package access members; list can access these directly
    int data; // data for this node
    ListNode nextNode; // reference to the next node in the list

    // constructor creates a ListNode that refers to object
    ListNode(int object) {
        this(object, null);
    }

    //constructor creates ListNode that refers to the specified object and to the next ListNode
    ListNode(int object, ListNode node) {
        data = object;
        nextNode = node;
    }
    //return reference to data in node
    int getData(){
        return data;
    }
    //return reference to next node in list
    ListNode getNext() {
        return nextNode;
    }
}//end class ListNode<T>