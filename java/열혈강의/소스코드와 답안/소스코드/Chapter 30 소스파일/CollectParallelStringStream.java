import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.stream.Stream;

class CollectParallelStringStream {
    public static void main(String[] args) {
        String[] words = {"Hello", "Box", "Robot", "Toy"};
        Stream<String> ss = Arrays.stream(words);
        
        List<String> ls = ss.parallel()
                          .filter(s -> s.length() < 5)                          
                          .collect(
                              () -> new ArrayList<>(),
                              (c, s) -> c.add(s),
                              (lst1, lst2) -> lst1.addAll(lst2));
    
        System.out.println(ls);
    }
}