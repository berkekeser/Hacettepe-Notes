import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class AdmissionDaoImpl implements IAdmissionDao {

    private HashMap<Integer, Integer> admissions = new HashMap<Integer, Integer>();

    @Override
    public Object getByID(int ID) {
        try{
            return admissions.get(ID);
        }catch (NullPointerException e) {
            System.out.println("There's no admissions for" + ID);
            return null;
        }
    }

    @Override
    public void deleteByID(int ID) {

        Iterator itr = admissions.entrySet().iterator();
        int removeKey = 0;
        while(itr.hasNext()) {
            Map.Entry pair = (Map.Entry) itr.next();
            if((int)pair.getValue() == ID) {
                removeKey = (int)pair.getKey();
                break;
            }
        }
        admissions.remove(removeKey);
    }

    @Override
    public void add(int admissionId, int patientId) {
        admissions.put(admissionId,patientId);
    }

    @Override
    public HashMap<Integer, Integer> getAll() {
        return admissions;
    }

}
