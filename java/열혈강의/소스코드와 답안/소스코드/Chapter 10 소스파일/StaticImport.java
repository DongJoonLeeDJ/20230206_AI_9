import static java.lang.Math.*;

class StaticImport {

    public static void main(String[] args) {
        System.out.println(E);
        System.out.println(PI);

        System.out.println(abs(-55));    // 절댓값 반환
        System.out.println(max(77, 88));   // 큰 값 반환
        System.out.println(min(33, 55));   // 작은 값 반환
    }
}
