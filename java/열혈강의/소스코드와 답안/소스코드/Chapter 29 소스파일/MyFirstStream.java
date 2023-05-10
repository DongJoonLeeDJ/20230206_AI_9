import java.util.Arrays;
import java.util.stream.IntStream;

class MyFirstStream {
    public static void main(String[] args) {
        int[] ar = {1, 2, 3, 4, 5};

        // 스트림 생성        
        IntStream stm1 = Arrays.stream(ar);

        // 중간 파이프 구성
        IntStream stm2 = stm1.filter(n -> n%2 == 1);

        // 최종 파이프 구성
        int sum = stm2.sum();

        System.out.println(sum);
    }
}