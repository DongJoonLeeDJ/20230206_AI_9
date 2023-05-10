import java.util.Arrays;

class MyFirstStream2 {
    public static void main(String[] args) {
        int[] ar = {1, 2, 3, 4, 5};

        int sum = Arrays.stream(ar)
                        .filter(n -> n%2 == 1)
                        .sum();

        System.out.println(sum);
    }
}