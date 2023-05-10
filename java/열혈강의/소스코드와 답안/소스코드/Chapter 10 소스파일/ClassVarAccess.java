class AccessWay {
    static int num = 0;
    
    AccessWay() {
        incrCnt();
    }
    
    void incrCnt() { 
        // 클래스 내부에서 이름을 통한 접근
        num++;
    }
}

class ClassVarAccess {
    public static void main(String[] args) {
        AccessWay way = new AccessWay();

        // 인스턴스의 이름을 통한 접근
        way.num++;

        // 클래스의 이름을 통한 접근
        AccessWay.num++;

        System.out.println("num = " + AccessWay.num);
    }
}