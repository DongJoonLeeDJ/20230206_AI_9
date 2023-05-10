import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.Files;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.DataInputStream;

class DataFilterInputStreamNewVer {
    public static void main(String[] args) {
        Path fp = Paths.get("data.dat");

        try(DataInputStream in = 
                 new DataInputStream(Files.newInputStream(fp))) {
            int num1 = in.readInt();
            double num2 = in.readDouble();
        
            System.out.println(num1);
            System.out.println(num2);
        }
        catch(IOException e) {
            e.printStackTrace();       
        }
    }
}