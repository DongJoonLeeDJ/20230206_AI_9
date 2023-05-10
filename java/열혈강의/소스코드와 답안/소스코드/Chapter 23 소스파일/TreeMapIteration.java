import java.util.TreeMap;
import java.util.Iterator;
import java.util.Set;

class TreeMapIteration {
    public static void main(String[] args) {
        TreeMap<Integer, String> map = new TreeMap<>();
        
        // Key-Value ��� ������ ����
        map.put(45, "Brown");
        map.put(37, "James");
        map.put(23, "Martin");

        // Key�� ��� �ִ� �÷��� �ν��Ͻ� ����
        Set<Integer> ks = map.keySet();

        // ��ü Key ��� (for-each�� ���)
        for(Integer n : ks)
            System.out.print(n.toString() + '\t');
        System.out.println();

        // ��ü Value ��� (for-each�� ���)
        for(Integer n : ks)
            System.out.print(map.get(n).toString() + '\t');
        System.out.println();

        // ��ü Value ��� (�ݺ��� ���)
        for(Iterator<Integer> itr = ks.iterator(); itr.hasNext(); )
            System.out.print(map.get(itr.next()) + '\t');
        System.out.println();
    }
}