import java.util.function.ToIntBiFunction;

class IBox {
    private int n; 

    public IBox(int i) { n = i; }

    public int larger(IBox b) {
        if(n > b.n)
            return n;
        else
            return b.n;
    }
}

class NoObjectMethodRef2 {
    public static void main(String[] args) {
        IBox ib1 = new IBox(5);
        IBox ib2 = new IBox(7);

        // 두 상자에 저장된 값 비교하여 더 큰 값 반환
        ToIntBiFunction<IBox, IBox> bf = IBox::larger;
        int bigNum = bf.applyAsInt(ib1, ib2);
        System.out.println(bigNum);}
}

// ToIntBiFunction<T, U>	int applyAsInt(T t, U u)