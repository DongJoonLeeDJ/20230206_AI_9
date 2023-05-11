import java.io.IOException;
import java.io.FileOutputStream;
import java.io.DataOutputStream;

class DataFilterOutputStream {
    public static void main(String[] args) {
        try(DataOutputStream out = 
                 new DataOutputStream(new FileOutputStream("data.dat"))) {
            out.writeInt(370);
            out.writeDouble(3.14);
        }
        catch(IOException e) {
            e.printStackTrace();       
        }
    }
}