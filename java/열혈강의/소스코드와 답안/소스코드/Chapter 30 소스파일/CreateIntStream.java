import java.util.Arrays;
import java.util.stream.IntStream;

class CreateIntStream {
    public static void showIntStream(IntStream is) {
        is.forEach(n -> System.out.print(n + "\t"));
        System.out.println();
    }

    public static void main(String[] args) {
        // 인자로 전달하는 값을 스트림으로
        IntStream is3 = IntStream.of(7, 5, 3); 
        showIntStream(is3);

        // 숫자 5 부터 8 이전까지 스트림으로
        IntStream is4 = IntStream.range(5, 8); 
        showIntStream(is4);

        // 숫자 5 부터 8 까지 스트림으로
        IntStream is5 = IntStream.rangeClosed(5, 8); 
        showIntStream(is5);
     }
}