import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.Files;
import java.io.IOException;
import java.io.FileWriter;
import java.io.BufferedWriter;

class StringWriterNewVer {
    public static void main(String[] args) {
        String ks = "공부에 있어서 돈이 꼭 필요한 것은 아니다.";
        String es = "Life is long if you know how to use it.";

        Path fp = Paths.get("String.txt");

        try(BufferedWriter bw = Files.newBufferedWriter(fp)) {   
            bw.write(ks, 0, ks.length());
            bw.newLine();
            bw.write(es, 0, es.length()); 
        }
        catch(IOException e) {
            e.printStackTrace();       
        }
    }
}

