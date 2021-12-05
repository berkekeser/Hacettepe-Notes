import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;


/**
 * Represents all file operations in this class.
 */
public class FileOperations {

    //Lists

    private List<Personnel> personnelList = new ArrayList<>();
    private List<Shift> shiftDetails = new ArrayList<>();

    //Methods

    /**
     * split given text file by line and store in array.
     */
    public String[] readFile(String path){
        try {
            int i = 0;
            int length = Files.readAllLines(Paths.get(path)).size();
            String[] results = new String[length];
            for(String line : Files.readAllLines(Paths.get(path))) {
                results[i++] = line;
            }
            return results;
        } catch (IOException e) {
            System.out.println("Error2: An error occurred while reading file.");
            e.printStackTrace();
            return null;
        }
    }

    /**
     * Create a new personnel after tokenized given line.
     * Created personnel store in list.
     * splitName[0] = name
     * splitName[1] = surname
     * tokens[1] = registration id
     * tokens[2] = position of personel
     * tokens[3] = year of start
     */
    public void readPersonnel(String line) {

        String[] tokens = line.split("\t");
        String[] splitName = tokens[0].split(" ");

        switch(tokens[2]) {
            case "FACULTY_MEMBER":
                personnelList.add(new FacultyMember(splitName[0], splitName[1], tokens[1], tokens[2], Integer.parseInt(tokens[3])));
                break;
            case "WORKER":
                personnelList.add(new Worker(splitName[0], splitName[1], tokens[1], tokens[2], Integer.parseInt(tokens[3])));
                break;
            case "SECURITY":
                personnelList.add(new Security(splitName[0], splitName[1], tokens[1], tokens[2], Integer.parseInt(tokens[3])));
                break;
            case "OFFICER":
                personnelList.add(new Officer(splitName[0], splitName[1], tokens[1], tokens[2], Integer.parseInt(tokens[3])));
                break;
            case "CHIEF":
                personnelList.add(new Chief(splitName[0], splitName[1], tokens[1], tokens[2], Integer.parseInt(tokens[3])));
                break;
            case "PARTTIME_EMPLOYEE":
                personnelList.add(new PartTime(splitName[0], splitName[1], tokens[1], tokens[2], Integer.parseInt(tokens[3])));
                break;
            case "RESEARCH_ASSISTANT":
                personnelList.add(new ResearchAssistant(splitName[0], splitName[1], tokens[1], tokens[2], Integer.parseInt(tokens[3])));
        }
    }

    /**
     * Read given shift data. Tokenize and store data in list.
     * tokens[0] = registration number
     * tokens[1] = week 1 work hours
     * tokens[2] = week 2 work hours
     * tokens[3] = week 3 work hours
     * tokens[4] = week 4 work hours
     */
    public void readShiftData(String line) {
        String[] tokens = line.split("\t");
        shiftDetails.add(new Shift(tokens[0],Integer.parseInt(tokens[1]),Integer.parseInt(tokens[2]),Integer.parseInt(tokens[3]),Integer.parseInt(tokens[4])));

    }

    /**
     * Search personnel in shift list. If register number matched function calculate salary for matched personnel.
     */
    public void calculateSalary() {

        //Search every personnel in shift list. If register ID match, calculate salary.
        for (Personnel personnel : personnelList) {
            for (Shift shiftDetail : shiftDetails) {
                if (personnel.getRegisterNumber().equals(shiftDetail.getRegisterNumber())) {
                    personnel.calculateSalary(shiftDetail.getWeek1(), shiftDetail.getWeek2(), shiftDetail.getWeek3(), shiftDetail.getWeek4());
                }
            }
        }

        //Iterate personnel list and write personnel details to file.
        for (Personnel p: personnelList) {
            writeToFile(p.getRegisterNumber(), p.toString());
        }
    }

    /**
     * Take file and concatenate with .txt extension.
     * If successfully write to file display message, otherwise throw an exception error.
     */
    private void writeToFile(String fileName, String p) {
        try {
            //create file
            String createFileName = fileName +".txt";
            File myObj = new File(createFileName);
            if (myObj.createNewFile()) {
                System.out.println("File created: " + myObj.getName());
            } else {
                System.out.println("File already exists.");
            }
            //Write file
            FileWriter myWriter = new FileWriter(createFileName);
            myWriter.write(p);
            myWriter.close();

        } catch (IOException e) {
            System.out.println("Error1: An error occurred while writing file.");
            e.printStackTrace();
        }
    }

}
