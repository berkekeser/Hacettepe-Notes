public class Main {

    public static void main(String[] args) {

        FileOperations input = new FileOperations();

        //Read given input and store in array.
        String [] personnelInput = input.readFile(args[0]);
        String [] monitoringInput = input.readFile(args[1]);

        //Tokenize array and store elements in list.
        for(String line : personnelInput) input.readPersonnel(line);
        for(String line : monitoringInput) input.readShiftData(line);

        //Calculate salary for each person and write to file.
        input.calculateSalary();

    }
}
