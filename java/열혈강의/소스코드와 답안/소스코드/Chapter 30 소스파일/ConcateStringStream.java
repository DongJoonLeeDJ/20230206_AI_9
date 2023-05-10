import java.util.Arrays;
import java.util.stream.Stream;

class ConcateStringStream {
    public static void main(String[] args) {
        Stream<String> ss1 = Stream.of("Cake", "Milk");
        Stream<String> ss2 = Stream.of("Lemon", "Jelly");
        
        // 스트림을 하나로 묶은 후 출력
        Stream.concat(ss1, ss2).forEach(s -> System.out.println(s));
     }
}