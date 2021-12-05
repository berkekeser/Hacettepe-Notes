public class Stack<T> extends List {
    //constructor
    public Stack() {
        super("stack");
    }

    // add object to stack
    public void push(int object) {
        insertAtFront(object);
    }

    //remove object from stack
    public int pop() throws EmptyListException {
        return removeFromFront();
    }

    public int peek() throws EmptyListException {
        return getElementFromTop();
    }

}
