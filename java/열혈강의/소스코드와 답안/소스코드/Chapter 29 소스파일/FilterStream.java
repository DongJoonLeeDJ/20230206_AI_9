import java.util.List;
import java.util.Arrays;

class FilterStream {
    public static void main(String[] args) {
        int[] ar = {1, 2, 3, 4, 5};
        Arrays.stream(ar)
            .filter(n -> n%2 == 1)
            .forEach(n -> System.out.print(n + "\t"));
        System.out.println();

        List<String> sl = Arrays.asList("Toy", "Robot", "Box");
        sl.stream()
            .filter(s -> s.length() == 3)
            .forEach(s -> System.out.print(s + "\t"));
        System.out.println();       
    }
}