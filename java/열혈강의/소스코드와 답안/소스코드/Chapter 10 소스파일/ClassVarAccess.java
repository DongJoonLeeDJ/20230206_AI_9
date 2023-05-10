class AccessWay {
    static int num = 0;
    
    AccessWay() {
        incrCnt();
    }
    
    void incrCnt() { 
        // Ŭ���� ���ο��� �̸��� ���� ����
        num++;
    }
}

class ClassVarAccess {
    public static void main(String[] args) {
        AccessWay way = new AccessWay();

        // �ν��Ͻ��� �̸��� ���� ����
        way.num++;

        // Ŭ������ �̸��� ���� ����
        AccessWay.num++;

        System.out.println("num = " + AccessWay.num);
    }
}