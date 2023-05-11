class UseWrapperClass {
    public static void showData(Object obj) {
        System.out.println(obj);
    }

    public static void main(String[] args) {
        // 정수 3으로 채워진 래퍼 인스턴스 생성
        Integer iInst = new Integer(3);
        showData(iInst);
        
        // 실수 7.15로 채워진 래퍼 인스턴스 생성
        showData(new Double(7.15));
    }
}