import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;
import java.io.IOException;

class CopyFileFromFiles {
    public static void main(String[] args) throws IOException {
        Path src = Paths.get("C:\\JavaStudy\\CopyFileFromFiles.java");
        Path dst = Paths.get("C:\\JavaStudy\\CopyFileFromFiles2.java");
        
        // src가 지시하는 파일을 dst가 지시하는 이름으로 복사
        Files.copy(src, dst, StandardCopyOption.REPLACE_EXISTING);
    }
}

