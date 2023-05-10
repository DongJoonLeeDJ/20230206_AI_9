import java.util.Iterator;
import java.util.HashSet;
import java.util.Set;

class SetCollectionFeature {
    public static void main(String[] args) {
        Set<String> set = new HashSet<>();
        set.add("Toy");
	set.add("Box");
	set.add("Robot");
	set.add("Box");
        
        System.out.println("인스턴스 수: " + set.size());
		
        for(Iterator<String> itr = set.iterator(); itr.hasNext(); )
            System.out.print(itr.next() + '\t');
        System.out.println();

        for(String s : set)
            System.out.print(s + '\t');
        System.out.println();
    }
}