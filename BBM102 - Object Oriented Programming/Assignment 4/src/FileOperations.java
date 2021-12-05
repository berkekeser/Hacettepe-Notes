import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class FileOperations {

    Stack<Integer> stack = new Stack<>();
    Queue<Integer> queue = new Queue<>();

    public void readFile(String filename) {

        try {
            FileReader reader = new FileReader(filename);
            BufferedReader br = new BufferedReader(reader);

            String line;

            while ((line = br.readLine()) != null) {

                if(line.startsWith("S")) {
                    String tokens[] = line.split(" ");

                    if(tokens[1].equals("removeGreater")) {
                        Stack<Integer> tempStack = new Stack<>();

                        while(!stack.isEmpty()) {
                            int num = stack.pop();
                            if(num <= Integer.parseInt(tokens[2])) {
                                tempStack.push(num);
                            }
                        }

                        while(!tempStack.isEmpty()) {
                            int num = tempStack.pop();
                            stack.push(num);
                        }
                        Main.stackWriter.write("After removeGreater " + Integer.parseInt(tokens[2]) +":\n");
                        Main.stackWriter.write(stack.toFile());

                    }

                    if(tokens[1].equals("calculateDistance")) {
                        int sum = 0;
                        Stack<Integer> tempStack = new Stack<>();
                        Stack<Integer> tempStack2 = new Stack<>();
                        ArrayList<Integer> numbers = new ArrayList<>();

                        while (!stack.isEmpty()) {
                            int number = stack.pop();
                            numbers.add(number);
                            tempStack.push(number);

                        }
                        while(!tempStack.isEmpty()) {
                            tempStack2.push(tempStack.pop());
                        }
                        stack = tempStack2;

                        for(int i=0; i<numbers.size();i++) {
                            for(int k= i+1;k<numbers.size();k++) {
                                sum += Math.abs(numbers.get(i) - numbers.get(k));
                            }
                        }

                        Main.stackWriter.write("After calculateDistance:\n");
                        Main.stackWriter.write("Total distance="+ sum + "\n");
                    }

                    if(tokens[1].equals("addOrRemove")) {
                        String tokens2[] = line.split(" ");
                        if(Integer.parseInt(tokens2[2]) < 0) {
                            for(int i=0;i<Math.abs(Integer.parseInt(tokens2[2])); i++) {
                                stack.pop();
                            }
                        }
                        if(Integer.parseInt(tokens2[2]) > 0){
                            for(int i=0;i<Integer.parseInt(tokens2[2]); i++) {
                                int randomNumber = (int) (Math.random() * (50));
                                stack.push(randomNumber);
                            }
                        }

                        Main.stackWriter.write("After addOrRemove " + Integer.parseInt(tokens2[2]) + ":\n");
                        Main.stackWriter.write(stack.toFile());

                    }

                    if(tokens[1].equals("reverse")) {
                        Stack<Integer> tempStack = new Stack<>();
                        Stack<Integer> tempStack2 = new Stack<>();

                        String tokensReverse[] = line.split(" ");

                        for(int i=0; i<Integer.parseInt(tokensReverse[2]); i++) {
                            int number = stack.pop();
                            tempStack.push(number);
                        }

                        for(int i=0; i<Integer.parseInt(tokensReverse[2]); i++) {
                            int number = tempStack.pop();
                            tempStack2.push(number);
                        }

                        for(int i=0; i<Integer.parseInt(tokensReverse[2]); i++) {
                            int number = tempStack2.pop();
                            stack.push(number);
                        }

                        Main.stackWriter.write("After reverse " + Integer.parseInt(tokensReverse[2]) + ":\n");
                        Main.stackWriter.write(stack.toFile());

                    }

                    if(tokens[1].equals("sortElements")) {
                        Stack<Integer> tempStack = new Stack<Integer>();
                        tempStack = sortStack(stack);
                        stack = tempStack;

                        Main.stackWriter.write("After sortElements:\n");
                        Main.stackWriter.write(stack.toFile());
                    }

                    if(tokens[1].equals("distinctElements")) {
                        Set<Integer> stackHashSet = new HashSet<>();
                        Stack <Integer> tempStack = new Stack<>();
                        while (!stack.isEmpty()) {
                            int number = stack.pop();
                            stackHashSet.add(number);
                            tempStack.push(number);
                        }

                        while(!tempStack.isEmpty()) {
                            stack.push(tempStack.pop());
                        }
                        Main.stackWriter.write("After distinctElements:\n");
                        Main.stackWriter.write("Total distinct element=" + stackHashSet.size() + "\n");
                    }
                }

                // Queue Operations
                if(line.startsWith("Q")) {
                    String tokens[] = line.split(" ");

                    if(tokens[1].equals("removeGreater")) {
                        Queue<Integer> tempQueue = new Queue<>();

                        while(!queue.isEmpty()) {
                            int number = queue.dequeue();
                            if(number < Integer.parseInt(tokens[2])) {
                                tempQueue.enqueue(number);
                            }
                        }
                        queue = tempQueue;

                        Main.queueWriter.write("After removeGreater " + Integer.parseInt(tokens[2]) +":\n");
                        Main.queueWriter.write(queue.toFile());
                    }

                    if(tokens[1].equals("calculateDistance")) {

                        int sum = 0;
                        Queue<Integer> tempQueue = new Queue<>();
                        ArrayList<Integer> numbers = new ArrayList<>();

                        while (!queue.isEmpty()) {
                            int number = queue.dequeue();
                            numbers.add(number);
                            tempQueue.enqueue(number);

                        }
                        while(!tempQueue.isEmpty()) {
                            queue.enqueue(tempQueue.dequeue());
                        }

                        for(int i=0; i<numbers.size();i++) {
                            for(int k= i+1;k<numbers.size();k++) {
                                sum += Math.abs(numbers.get(i) - numbers.get(k));
                            }
                        }
                        Main.queueWriter.write("After calculateDistance:\n");
                        Main.queueWriter.write("Total distance="+ sum + "\n");
                    }

                    if(tokens[1].equals("addOrRemove")) {
                        String tokens2[] = line.split(" ");
                        if(Integer.parseInt(tokens2[2]) < 0) {
                            for(int i=0;i<Math.abs(Integer.parseInt(tokens2[2])); i++) {
                                queue.dequeue();
                            }
                        }
                        if(Integer.parseInt(tokens2[2]) > 0){
                            for(int i=0;i<Integer.parseInt(tokens2[2]); i++) {
                                int randomNumber = (int) (Math.random() * (50));
                                queue.enqueue(randomNumber);
                            }
                        }
                        Main.queueWriter.write("After addOrRemove " + Integer.parseInt(tokens2[2]) + ":\n");
                        Main.queueWriter.write(queue.toFile());
                    }

                    if(tokens[1].equals("reverse")) {
                        Queue<Integer> tempQueue = new Queue<>();
                        Queue<Integer> tempQueue2 = new Queue<>();
                        Stack<Integer> tempStack = new Stack<>();

                        String tokensReverse[] = line.split(" ");

                        for(int i=0; i<Integer.parseInt(tokensReverse[2]); i++) {
                            int number = queue.dequeue();
                            tempStack.push(number);
                        }

                        while (!queue.isEmpty()) {
                            tempQueue.enqueue(queue.dequeue());
                        }

                        while(!tempStack.isEmpty()) {
                            tempQueue2.enqueue(tempStack.pop());
                        }

                        while(!tempQueue.isEmpty()) {
                            tempQueue2.enqueue(tempQueue.dequeue());
                        }
                        queue = tempQueue2;

                        Main.queueWriter.write("After reverse " + Integer.parseInt(tokensReverse[2]) + ":\n");
                        Main.queueWriter.write(queue.toFile());
                    }

                    if(tokens[1].equals("sortElements")) {
                        Stack<Integer> tempStack = new Stack<>();
                        Stack<Integer> orderedStack = new Stack<>();

                        while (!queue.isEmpty()) {
                            tempStack.push(queue.dequeue());
                        }

                        orderedStack = sortStack(tempStack);

                        while(!orderedStack.isEmpty()) {
                            queue.enqueue(orderedStack.pop());
                        }

                        Main.queueWriter.write("After sortElements:\n");
                        Main.queueWriter.write(queue.toFile());
                    }

                    if(tokens[1].equals("distinctElements")) {
                        Set<Integer> queueHashSet = new HashSet<>();
                        Queue<Integer> tempQueue = new Queue<>();

                        while (!queue.isEmpty()) {
                            int number = queue.dequeue();
                            queueHashSet.add(number);
                            tempQueue.enqueue(number);
                        }

                        while(!tempQueue.isEmpty()) {
                            queue.enqueue(tempQueue.dequeue());
                        }

                        Main.queueWriter.write("After distinctElements:\n");
                        Main.queueWriter.write("Total distinct element=" + queueHashSet.size() + "\n");
                    }
                }

            }
        }catch(IOException e) {
            System.out.println("Error: An error occurred while reading " + filename + " file.");
            e.printStackTrace();
        }
    }

    public void readStack(String filename) {

        try {
            FileReader reader = new FileReader(filename);
            BufferedReader br = new BufferedReader(reader);

            String line;

            // push numbers to stack.
            while ((line = br.readLine()) != null) {
                String tokens[] = line.split(" ");

                for(int i = tokens.length-1 ; i>=0 ;i--) {
                    stack.push(Integer.parseInt(tokens[i]));
                }
            }

        }catch(IOException e) {
            System.out.println("Error: An error occurred while reading " + filename + " file.");
            e.printStackTrace();
        }
    }

    public void readQueue(String filename) {

        try {
            FileReader reader = new FileReader(filename);
            BufferedReader br = new BufferedReader(reader);

            String line;

            // enqueue numbers to queue.
            while ((line = br.readLine()) != null) {
                String tokens[] = line.split(" ");

                for(int i = 0; i<tokens.length; i++) {
                    queue.enqueue(Integer.parseInt(tokens[i]));
                }
            }
        }catch(IOException e) {
            System.out.println("Error: An error occurred while reading " + filename + " file.");
            e.printStackTrace();
        }
    }

    public Stack<Integer> sortStack(Stack stack) {
        Stack<Integer> tempStack = new Stack<Integer>();
        while(!stack.isEmpty())
        {
            int number = (int)stack.pop();
            while(!tempStack.isEmpty() && (tempStack.peek() < number))
            {
                stack.push(tempStack.pop());
            }
            tempStack.push(number);
        }
        return tempStack;
    }


}
