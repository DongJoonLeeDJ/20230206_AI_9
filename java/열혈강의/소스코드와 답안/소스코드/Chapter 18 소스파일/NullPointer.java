class NullPointer { 
    public static void main(String[] args) {
        String str = null;
        System.out.println(str);    // null Ãâ·Â
        int len = str.length();    // Exception! 
    }
}