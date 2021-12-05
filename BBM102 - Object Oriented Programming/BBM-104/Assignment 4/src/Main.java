import java.io.FileWriter;
import java.io.IOException;

public class Main {

    public static FileWriter stackWriter;
    public static FileWriter queueWriter;

    public static FileWriter stackUpdater;
    public static FileWriter queueUpdater;

    public static void main(String[] args) throws IOException {

        stackWriter = new FileWriter("stackOut.txt");
        queueWriter = new FileWriter("queueOut.txt");

        FileOperations input = new FileOperations();
        input.readStack("stack.txt");
        input.readQueue("queue.txt");

        input.readFile(args[0]);

        queueUpdater = new FileWriter("queue.txt");
        stackUpdater = new FileWriter("stack.txt");

        queueUpdater.write(input.queue.toFile());
        stackUpdater.write(input.stack.toFile());

        //Close files
        stackUpdater.close();
        queueUpdater.close();
        stackWriter.close();
        queueWriter.close();

    }
}
