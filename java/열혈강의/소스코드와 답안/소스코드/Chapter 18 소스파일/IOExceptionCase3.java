import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.Files; 
import java.io.BufferedWriter;
import java.io.IOException;
 
class IOExceptionCase3 { 
    public static void main(String[] args) {
        try {
            md1();
        }
        catch(IOException e) {
            e.printStackTrace();
        }
    }
    public static void md1() throws IOException {
        md2();
    }    
    public static void md2() throws IOException {
        Path file = Paths.get("C:\\javastudy\\Simple.txt");
        BufferedWriter writer = null;
        writer = Files.newBufferedWriter(file);    // IOException �߻� ����
        writer.write('A');     // IOException �߻� ����
        writer.write('Z');     // IOException �߻� ����

        if(writer != null)
            writer.close();     // IOException �߻� ����
    }
}