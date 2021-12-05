import java.io.FileWriter;
import java.io.IOException;

public class Main {

        public static FileWriter outputWriter;
        public static FileWriter patientWriter;
        public static FileWriter admissionWriter;

    public static void main(String[] args) throws IOException {

        outputWriter = new FileWriter("output.txt");
        FileOperations fileOperations = new FileOperations();
        fileOperations.readPatient("patient.txt");
        fileOperations.readAdmission("admission.txt");
        fileOperations.readInput(args[0]);
        admissionWriter = new FileWriter("admission.txt");
        patientWriter = new FileWriter("patient.txt");
        fileOperations.patientDao.writePatientsToFile();
        fileOperations.writeAdmissionToFile();

        //close file
        patientWriter.close();
        outputWriter.close();
        admissionWriter.close();
    }
}
