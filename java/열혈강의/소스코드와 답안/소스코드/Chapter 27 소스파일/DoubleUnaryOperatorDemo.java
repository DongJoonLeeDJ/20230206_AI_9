import java.util.function.DoubleUnaryOperator;

class DoubleUnaryOperatorDemo {
    public static void main(String[] args) {
        DoubleUnaryOperator cti = d -> d * 0.393701;
        DoubleUnaryOperator itc = d -> d * 2.54;

        System.out.println("1cm = " + cti.applyAsDouble(1.0) + "inch");
        System.out.println("1inch = " + itc.applyAsDouble(1.0) + "cm");
    }
}