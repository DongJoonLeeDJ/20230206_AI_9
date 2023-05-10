package com.fxmx.simple;

public class Circle {
    double rad;
    final double PI;
    	
    public Circle(double r) {
        rad = r;
        PI = 3.14;
    }
    
    // 원의 둘레 길이 반환
    public double getPerimeter() {
        return (rad * 2) * PI;
    }
}