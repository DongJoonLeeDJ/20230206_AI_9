package mytest.myjava.mycode;//폴더명, 패키지 만들고 그 안에 파일을 만들어야 함(권장사항)

import java.util.Scanner;

public class WelcomeMyLotto {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("반지름을 입력하세요: ");
        double radius = input.nextDouble();
        double area = Math.PI * radius * radius;
        double circumference = 2 * Math.PI * radius;
        System.out.printf("원의 넓이: %.2f\n", area);
        System.out.printf("원의 둘레: %.2f\n", circumference);
    }
}
