package mytest.myjava.mycode;//������, ��Ű�� ����� �� �ȿ� ������ ������ ��(�������)

import java.util.Scanner;

public class WelcomeMyLotto {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("�������� �Է��ϼ���: ");
        double radius = input.nextDouble();
        double area = Math.PI * radius * radius;
        double circumference = 2 * Math.PI * radius;
        System.out.printf("���� ����: %.2f\n", area);
        System.out.printf("���� �ѷ�: %.2f\n", circumference);
    }
}
