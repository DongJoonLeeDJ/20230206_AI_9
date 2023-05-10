import java.util.stream.IntStream;

class MatchStream {
    public static void main(String[] args) {
        boolean b = IntStream.of(1, 2, 3, 4, 5)
                          .allMatch(n -> n%2 == 0);
        System.out.println("모두 짝수이다. " + b);

        b = IntStream.of(1, 2, 3, 4, 5)
                    .anyMatch(n -> n%2 == 0);
        System.out.println("짝수가 하나는 있다. " + b);

        b = IntStream.of(1, 2, 3, 4, 5)
                    .noneMatch(n -> n%2 == 0);
        System.out.println("짝수가 하나도 없다. " + b);
    }
}