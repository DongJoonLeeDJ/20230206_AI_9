import java.util.List;
import java.util.Arrays;
import java.util.stream.Stream;
import java.util.function.BinaryOperator;

class ToParallelStream {
    public static void main(String[] args) {
        List<String> ls = Arrays.asList("Box", "Simple", "Complex", "Robot");
        Stream<String> ss = ls.stream();
        
        BinaryOperator<String> lc = 
            (s1, s2) -> { 
               if(s1.length() > s2.length())
                   return s1;
               else 
                   return s2;                   
            };
        
        String str = ss.parallel()
                      .reduce("", lc);
      
        System.out.println(str);
    }
}