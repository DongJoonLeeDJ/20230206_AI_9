import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.Files;
import java.nio.file.StandardOpenOption;
import java.io.IOException;

class SimpleBinWriteRead {
    public static void main(String[] args) throws IOException {
        Path fp = Paths.get("C:\\JavaStudy\\simple.bin");
        fp = Files.createFile(fp);

        byte buf1[] = {0x13, 0x14, 0x15};
        for(byte b : buf1)
            System.out.print(b + "\t");
        System.out.println();
        
        // 파일에 바이너리 데이터 쓰기
        Files.write(fp, buf1, StandardOpenOption.APPEND);
        
        // 파일로부터 바이너리 데이터 읽기
        byte buf2[] = Files.readAllBytes(fp);
        
        for(byte b : buf2)
            System.out.print(b + "\t");
        System.out.println();
    }
}

