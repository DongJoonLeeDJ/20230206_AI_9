import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.IOException;

class Write7ToFile {
    public static void main(String[] args) throws IOException {
        OutputStream out = new FileOutputStream("data.dat");
        out.write(7);
        out.close();       
    }
}