public class Queue<T> extends List {

    //constructor
    public Queue() {
            super("queue");
    }

    // add objecto to queue
    public void enqueue(int object) {
        insertAtBack(object);
    }

    public int dequeue() throws EmptyListException {
        return removeFromFront();
    }

}