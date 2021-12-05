import java.io.*;
import java.lang.*;
import java.util.*;

public class FileOperations {

    // DAO implementation.
    IPatientDao patientDao = new PatientDaoImpl();
    IAdmissionDao admissionDao = new AdmissionDaoImpl();

    private ArrayList <Examination> examinationList = new ArrayList<>();

    public void readAdmission(String filename) {

        int admissionId = 0;
        int patientId = 0;

        try {
            FileReader reader = new FileReader(filename);
            BufferedReader br = new BufferedReader(reader);

            String line;

            while((line = br.readLine()) != null) {

                String tokens[] = line.split("\t");

                try {
                    admissionId = Integer.parseInt(tokens[0]);
                    patientId = Integer.parseInt(tokens[1]);
                    admissionDao.add(admissionId,patientId);


                } catch (NumberFormatException e) {

                }

                if(tokens[0].equals("Inpatient")) {

                    Examination tempExamination = new Inpatient();

                    String examination[] = tokens[1].split(" ");

                    if(examination.length == 4) {
                        System.out.println("Admission.txt has 4 argument for admission. Program terminated.");
                        System.exit(0);
                    }

                    for(String s : examination) {
                        if(s.equals("tests")) {
                            tempExamination = new Tests(tempExamination);
                        }else if(s.equals("doctorvisit")) {
                            tempExamination = new DoctorVisit(tempExamination);
                        }else if(s.equals("measurements")) {
                            tempExamination = new Measurements(tempExamination);
                        } else if(s.equals("imaging")) {
                            tempExamination = new Imaging(tempExamination);
                        }
                    }
                    tempExamination.setPatientId(patientId);
                    examinationList.add(tempExamination);
                    admissionDao.add(admissionId,patientId);
                    tempExamination.getCost();

                }else if(tokens[0].equals("Outpatient")) {

                    Examination tempExamination = new Outpatient();
                    String examination[] = tokens[1].split(" ");

                    if(examination.length == 4) {
                        System.out.println("Admission.txt has 4 argument for admission. Program terminated.");
                        System.exit(0);
                    }

                    for(String s : examination) {
                        if(s.equals("tests")) {
                            tempExamination = new Tests(tempExamination);
                        }else if(s.equals("doctorvisit")) {
                            tempExamination = new DoctorVisit(tempExamination);
                        }else if(s.equals("measurements")) {
                            tempExamination = new Measurements(tempExamination);
                        } else if(s.equals("imaging")) {
                            tempExamination = new Imaging(tempExamination);
                        }
                    }
                    admissionDao.add(admissionId,patientId);
                    tempExamination.setPatientId(patientId);
                    examinationList.add(tempExamination);
                }
            }
        }catch (IOException e) {
            System.out.println("Error: An error occurred while reading " +filename +" file.");
            e.printStackTrace();
        }
    }

    public void readPatient(String filename) {

        try {
            FileReader reader = new FileReader(filename);
            BufferedReader br = new BufferedReader(reader);

            String line;

            while ((line = br.readLine()) != null) {

                String tokens[] = line.split("\t");
                String fullName[] = tokens[1].split(" ");
                String address[] = tokens[3].split(": ");

                // If phone number is wrong patient won't create.
                if(patientDao.checkPhoneNumber(tokens[2])) {
                    Patient tempPatient = new Patient(Integer.parseInt(tokens[0]),fullName[0],fullName[1],tokens[2], address[1]);
                    patientDao.add(tempPatient);
                }

            }
        }catch (IOException e) {
            System.out.println("Error: An error occurred while reading " +filename +" file.");
            e.printStackTrace();
        }
    }

    public void readInput(String fileName) {

        try {
            FileReader reader = new FileReader(fileName);
            BufferedReader br = new BufferedReader(reader);

            String line;
            while ((line = br.readLine()) != null) {

                if (line.startsWith("AddPatient")) {

                    String tokens[] = line.split(" ");

                    // concatenate address token.
                    String address = tokens[5]+ " " + tokens[6] + " " + tokens[7] + " "+ tokens[8];

                    String phoneNumber = tokens[4];

                    //If phone number valid create patient.
                    if(patientDao.checkPhoneNumber(phoneNumber)){
                        Patient tempPatient = new Patient(Integer.parseInt(tokens[1]),tokens[2],tokens[3],tokens[4], address);
                        patientDao.add(tempPatient);
                        Main.outputWriter.write("Patient " + tempPatient.getId() + " " + tempPatient.getName() + " added\n");
                    }

                }

                if (line.startsWith("RemovePatient")) {
                    String tokens[] = line.split( " ");
                    patientDao.deleteByID(Integer.parseInt(tokens[1]));
                    admissionDao.deleteByID(Integer.parseInt(tokens[1]));
                    removeExaminationById(tokens[1]);
                }

                if (line.startsWith("CreateAdmission")) {
                    String tokens[] = line.split(" ");
                    int admissionId = Integer.parseInt(tokens[1]);
                    int patientId = Integer.parseInt(tokens[2]);

                    admissionDao.add(admissionId,patientId);
                    Main.outputWriter.write("Admission " +admissionId + " created\n");

                }

                if (line.startsWith("AddExamination")) {

                    String tokens[] = line.split(" ");
                    int examinationID = Integer.parseInt(tokens[1]);
                    String allExaminations = "";
                    for(int i=3;i<tokens.length;i++) {
                        allExaminations+= tokens[i];
                        if(i != tokens.length -1) {
                            allExaminations += " ";
                        }
                    }

                    String examination[] = allExaminations.split(" ");

                    if(examination.length == 4) {
                        System.out.println("Program terminated due to too many arguments for AddExamination operations.");
                        System.exit(0);
                    }

                    if(tokens[2].equals("Inpatient")) {

                        Examination tempExamination = new Inpatient();
                        // Decorator Design Pattern Approach
                        for(String s : examination) {
                            if(s.equals("tests")) {
                                tempExamination = new Tests(tempExamination);
                            }else if(s.equals("doctorvisit")) {
                                tempExamination = new DoctorVisit(tempExamination);
                            }else if(s.equals("measurements")) {
                                tempExamination = new Measurements(tempExamination);
                            } else if(s.equals("imaging")) {
                                tempExamination = new Imaging(tempExamination);
                            }
                        }

                        try {
                            int patientId = (int)admissionDao.getByID(examinationID);
                            tempExamination.setPatientId(patientId);
                            examinationList.add(tempExamination);
                            Main.outputWriter.write("Inpatient examination added to admission " + examinationID +"\n");
                        }catch (NullPointerException e) {
                            System.out.println("Patient has another examination id.");
                        }


                    }

                    if(tokens[2].equals("Outpatient")) {

                        Examination tempExamination = new Outpatient();
                        // Decorator Design Pattern Approach
                        for(String s : examination) {
                            if(s.equals("tests")) {
                                tempExamination = new Tests(tempExamination);
                            }else if(s.equals("doctorvisit")) {
                                tempExamination = new DoctorVisit(tempExamination);
                            }else if(s.equals("measurements")) {
                                tempExamination = new Measurements(tempExamination);
                            }else if(s.equals("imaging")) {
                                tempExamination = new Imaging(tempExamination);
                            }
                        }
                        try {
                            int patientId = (int)admissionDao.getByID(examinationID);
                            tempExamination.setPatientId(patientId);
                            examinationList.add(tempExamination);
                            Main.outputWriter.write("Outpatient examination added to admission " + examinationID +"\n");
                        }catch (NullPointerException e) {
                            System.out.println("Patient has another examination id.");
                        }
                    }
                }

                if (line.startsWith("ListPatients")) {
                    Main.outputWriter.write("Patient List:\n");
                    patientDao.getAll();
                }

                if (line.startsWith("TotalCost")) {
                    String tokens[] = line.split(" ");
                    int admissionID = Integer.parseInt(tokens[1]);
                    totalCost(admissionID);
                }
            }

        }catch (IOException e) {
            System.out.println("Error: An error occurred while reading file.");
            e.printStackTrace();
        }

    }

    private void removeExaminationById(String token) {
        int removeId = Integer.parseInt(token);
        for(int i=0;i<examinationList.size();i++) {
            if(examinationList.get(i).getPatientId() == removeId) {
                examinationList.remove(i);
            }
        }
    }

    private void totalCost(int admissionID) throws IOException {

        try {
            int patientId = (int)admissionDao.getByID(admissionID);

            int total = 0;
            Main.outputWriter.write("TotalCost for admission " + admissionID +"\n");
            for(Examination e: examinationList) {
                if (e.getPatientId() == patientId) {
                    total += e.getCost();
                    Main.outputWriter.write("\t\t" + e.printOperations("totalCost") + ""+(int)e.getCost()+"$\n");
                }
            }
            Main.outputWriter.write("\t\tTotal: "+total+"$\n");

        }catch (NullPointerException e) {
            System.out.println("There is no admission for " + admissionID);
        }

    }

    public void writeAdmissionToFile() throws IOException {
        HashMap<Integer, Integer> tempAdmissions;
        tempAdmissions = admissionDao.getAll();
        Iterator<Map.Entry<Integer, Integer>> itr = tempAdmissions.entrySet().iterator();

        while(itr.hasNext()) {
            Map.Entry<Integer, Integer> pair = itr.next();
            Main.admissionWriter.write(pair.getKey() + "\t" + pair.getValue() +"\n");
            for(int i=0; i<examinationList.size();i++) {
                if(examinationList.get(i).getPatientId() == pair.getValue()) {
                    Main.admissionWriter.write(examinationList.get(i).printOperations("admission") +"\n");
                }
            }
        }
    }

}
