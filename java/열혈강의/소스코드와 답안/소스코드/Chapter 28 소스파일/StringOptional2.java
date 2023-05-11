import java.util.Optional;

class StringOptional2 {
    public static void main(String[] args) {
        Optional<String> os1 = Optional.of(new String("Toy1"));
        Optional<String> os2 = Optional.ofNullable(new String("Toy2"));

        // 람다식 버전
        os1.ifPresent(s -> System.out.println(s));

        // 메소드 참조 버전
        os2.ifPresent(System.out::println);
    }
}