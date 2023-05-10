import java.util.Arrays;

class ArraySearch {
    public static void main(String[] args) {
        int[] ar = {33, 55, 11, 44, 22};

        Arrays.sort(ar);
        for(int n : ar)
            System.out.print(n + "\t");
        System.out.println();

        int idx = Arrays.binarySearch(ar, 33);
        System.out.println("Index of 33: " + idx);

    }
}
