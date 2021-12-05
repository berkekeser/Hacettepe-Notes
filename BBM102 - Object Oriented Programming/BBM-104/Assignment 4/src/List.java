public class List {
    private ListNode firstNode;
    private ListNode lastNode;
    private String name;

    public List() {
        this("list");
    }

    List(String listName) {
        name = listName;
        firstNode = lastNode = null;
    }

    //get data from top
    public int getElementFromTop() {
        if (isEmpty()) //throw exception if List is empty.
            throw new EmptyListException();
        int element = firstNode.data;
        return element;
    }

    //insert item at front of List
    public void insertAtFront(int insertItem) {
        if (isEmpty()) // firstNode and lastNode refer to same object
            firstNode = lastNode = new ListNode(insertItem);
        else // firstNode refers to new node
            firstNode = new ListNode(insertItem, firstNode);
    }

    //insert item at end of List
    public void insertAtBack(int insertItem) {
        if (isEmpty()) // firstNode and lastNode refer to same object
            firstNode = lastNode = new ListNode(insertItem);
        else // lastNode's nextNode refers to new node.
            lastNode = lastNode.nextNode = new ListNode(insertItem);
    }

    //remove first node from list
    public int removeFromFront() throws EmptyListException {
        if (isEmpty()) //throw exception if List is empty.
            throw new EmptyListException();
        int removedItem = firstNode.data; // retrieve data being removed

        //update references firstNode and lastNode
        if(firstNode == lastNode)
            firstNode = lastNode = null;
        else
            firstNode = firstNode.nextNode;

        return removedItem; // return removed note data
    }

    //determine whether list is empty.
    public boolean isEmpty() {
        return firstNode == null; // return true if list is empty.
    }
    //output list contents


    public String toFile() {
        String empty = new String();
        if(isEmpty()) {
            return "Empty" + name;
        }
        //System.out.printf("The %s is: ", name);
        ListNode current = firstNode;

        //while not at end of list, output current node's data
        while(current != null) {
            empty += current.data + " ";
            current = current.nextNode;
        }
        return empty + "\n";
    }



}