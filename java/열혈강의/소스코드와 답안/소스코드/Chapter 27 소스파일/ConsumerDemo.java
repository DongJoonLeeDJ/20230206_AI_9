import java.util.function.Consumer;

class ConsumerDemo {
    public static void main(String[] args) {
        Consumer<String> c = s -> System.out.println(s);
        
        c.accept("Pineapple");    // 출력이라는 결과를 보임
        c.accept("Strawberry");
    }
}