import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.IOException;

class Write7ToFile3 {
    public static void main(String[] args) {
        try(OutputStream out = new FileOutputStream("data.dat")) {
            out.write(7);
        }
        catch(IOException e) {
            e.printStackTrace();       
        }
    }
}