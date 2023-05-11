class Point { 
    int xPos, yPos;

    public Point(int x, int y) {
        xPos = x;
        xPos = y;
    }

    public void showPointInfo() { 
        System.out.println("[" + xPos + ", " + yPos + "]"); 
    }
}

class Circle
{
    int rad;	// 반지름
    Point center;    // 원의 중심
    
    public Circle(int x, int y, int r) {
        center = new Point(x, y);
        rad = r;
    }
    
    public void showCircleInfo() {
        System.out.println("radius: " + rad);
        center.showPointInfo();
    }
}

class UseCircle {
    public static void main(String[] args) {
        // 좌표 [2, 2] 반지름 4인 원의 생성
        Circle c = new Circle(2, 2, 4);

        // 원의 정보 출력
        c.showCircleInfo();
    }
}

