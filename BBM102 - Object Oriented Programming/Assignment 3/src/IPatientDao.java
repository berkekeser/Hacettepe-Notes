import java.util.ArrayList;

public interface IPatientDao {

    Patient getByID(int ID);
    void deleteByID(int ID);
    void add(Patient patient);
    ArrayList getAll();
    boolean checkPhoneNumber(String number);
    void writePatientsToFile();
}
