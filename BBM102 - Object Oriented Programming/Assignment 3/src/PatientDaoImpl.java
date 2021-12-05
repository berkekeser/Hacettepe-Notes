import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;

public class PatientDaoImpl implements IPatientDao {

    private ArrayList<Patient> patientList = new ArrayList<>();

    @Override
    public Patient getByID(int ID) {
        Patient tempPatient = new Patient();
        tempPatient.setId(ID);
        for(Patient p: patientList) {
            if(p.getId() == tempPatient.getId()) {
                tempPatient = p;
            } else {
                return null;
            }
        }
        return tempPatient;
    }

    @Override
    public void deleteByID(int ID) {
        Patient tempRemove = new Patient();
        tempRemove.setId(ID);
        for(int i=0; i<patientList.size();i++) {
            if(patientList.get(i).getId() == ID) {
                tempRemove = patientList.get(i);
                patientList.remove(tempRemove);
                try {
                    Main.outputWriter.write("Patient " + tempRemove.getId() + " " + tempRemove.getName() + " removed\n");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    @Override
    public void add(Patient patient) {
        int patientId = patient.getId();
        boolean check = false;
        for(Patient p : patientList) {
            if(p.getId() == patientId) {
                check = true;
            }
        }
        if(!check) {
            patientList.add(patient);
        }else {
            System.out.println("Patient id " +patientId + " already taken for another patient.");
        }
    }

    @Override
    public ArrayList getAll() {
        patientList.sort(Comparator.comparing(Patient::getName));
        for(Patient p : patientList) {
            try {
                Main.outputWriter.write(p.toString());
            }catch (IOException e) {
                e.printStackTrace();
            }
        }
        return patientList;
    }


    @Override
    public boolean checkPhoneNumber(String number) {

        String tokens[] = number.split("-");

        int nCode = tokens[0].length();
        int nNumber = tokens[1].length();

        try {
            int code = Integer.parseInt(tokens[0]);
            int number2 = Integer.parseInt(tokens[1]);

            if(nCode == 3 && nNumber == 7) {
                return true;
            }else{
                System.out.println("##Error## Phone number code part must be 3 digits and number part must be 7 seven digits.");
            }

        }catch(IllegalArgumentException e) {
            System.out.println("##Error## Phone numbers must be digits.");
        }
        return false;
    }

    public void writePatientsToFile() {
        patientList.sort(Comparator.comparing(Patient::getId));
        for(Patient p : patientList) {
            try {
                Main.patientWriter.write(p.toString());
            }catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

}
