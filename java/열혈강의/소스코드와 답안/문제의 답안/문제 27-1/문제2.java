import java.util.List;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Collections;

class SLenComparatorLambdaVer {
    public static void main(String[] args) {
        List<String> list = new ArrayList<>();
        list.add("Robot");
        list.add("Lambda");
        list.add("Box");

        Collections.sort(list, (s1, s2) -> s1.length() - s2.length());    // Á¤·Ä

        for(String s : list)
            System.out.println(s);
    }
}