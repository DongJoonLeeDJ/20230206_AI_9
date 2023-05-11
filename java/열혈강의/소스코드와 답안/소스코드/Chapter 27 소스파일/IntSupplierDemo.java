import java.util.Random;
import java.util.List;
import java.util.ArrayList;
import java.util.function.IntSupplier;

class IntSupplierDemo {
    public static List<Integer> makeIntList(IntSupplier is, int n) {
        List<Integer> list = new ArrayList<>();    

        for(int i = 0; i < n; i++)
            list.add(is.getAsInt());

        return list;
    }
    
    public static void main(String[] args) {
        IntSupplier  ispr = () -> {
            Random rand = new Random();
            return rand.nextInt(50);
        };

        List<Integer> list = makeIntList(ispr, 5);
        System.out.println(list);

        list = makeIntList(ispr, 10);
        System.out.println(list);
    }
}