import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.function.Predicate;

class RemoveIfDemo {
    public static void main(String[] args) {
        List<Integer> ls1 = Arrays.asList(1, -2, 3, -4, 5);
        ls1 = new ArrayList<>(ls1);

        List<Double> ls2 = Arrays.asList(-1.1, 2.2, 3.3, -4.4, 5.5);
        ls2 = new ArrayList<>(ls2);
        
        Predicate<Number> p = n -> n.doubleValue() < 0.0;
        ls1.removeIf(p);
        ls2.removeIf(p);

        System.out.println(ls1);
        System.out.println(ls2);
    }
}