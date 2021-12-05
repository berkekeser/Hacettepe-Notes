import java.util.HashMap;

public interface IAdmissionDao {

    Object getByID(int ID);
    void deleteByID(int ID);
    void add(int admissionId, int patientId);
    HashMap<Integer, Integer> getAll();

}
