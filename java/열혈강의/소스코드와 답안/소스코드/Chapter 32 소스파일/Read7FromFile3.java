import java.io.InputStream;
import java.io.FileInputStream;
import java.io.IOException;

class Read7FromFile3 {
    public static void main(String[] args) {         
        try(InputStream in = new FileInputStream("data.dat")) {
            int dat = in.read();
            System.out.println(dat);
        } 
        catch(IOException e) {
            e.printStackTrace();       
        }      
    }
}