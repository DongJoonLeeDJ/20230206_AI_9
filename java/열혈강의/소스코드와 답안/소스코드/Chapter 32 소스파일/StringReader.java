import java.io.IOException;
import java.io.FileReader;
import java.io.BufferedReader;

class StringReader {
    public static void main(String[] args) {       
        try(BufferedReader br = new BufferedReader(new FileReader("String.txt"))) {
            String str;

            while(true) {
                str = br.readLine();
                if(str == null)
                    break;
                System.out.println(str);
            }
        }
        catch(IOException e) {
            e.printStackTrace();       
        }
    }
}

