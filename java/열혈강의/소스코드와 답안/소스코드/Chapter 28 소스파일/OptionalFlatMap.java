import java.util.Optional;

class OptionalFlatMap {
    public static void main(String[] args) {
        Optional<String> os1 = Optional.of("Optional String");

        Optional<String> os2 = os1.map(s -> s.toUpperCase());
        System.out.println(os2.get());

        Optional<String> os3 = os1.flatMap(s -> Optional.of(s.toLowerCase()));
        System.out.println(os3.get());
    }
}