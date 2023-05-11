class SimpleOperation {
    public static void main(String[] args) {
        simpleOpr(7, 3);
    }
    
    public static void simpleOpr(int n1, int n2) {
        System.out.println("µ¡¼À °á°ú: " + (n1 + n2));
        System.out.println("»¬¼À °á°ú: " + (n1 - n2));
        System.out.println("°ö¼À °á°ú: " + (n1 * n2));
        System.out.println("³ª´°¼ÀÀÇ ¸ò: " + (n1 / n2));
        System.out.println("³ª´°¼ÀÀÇ ³ª¸ÓÁö: " + (n1 % n2));
    }
}
