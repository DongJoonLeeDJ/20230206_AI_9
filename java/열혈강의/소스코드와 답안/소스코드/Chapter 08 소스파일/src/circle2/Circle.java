package com.fxmx.simple;

public class Circle {
    double rad;
    final double PI;
    	
    public Circle(double r) {
        rad = r;
        PI = 3.14;
    }
    
    // ���� �ѷ� ���� ��ȯ
    public double getPerimeter() {
        return (rad * 2) * PI;
    }
}