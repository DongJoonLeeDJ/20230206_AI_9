package com.wxfx.smart;

public class Circle {
    double rad;
    final double PI;
    
    public Circle(double r) {
        rad = r;
        PI = 3.14;
    }
        
    // ���� ���� ��ȯ
    public double getArea() {
        return (rad * rad) * PI;
    }
}