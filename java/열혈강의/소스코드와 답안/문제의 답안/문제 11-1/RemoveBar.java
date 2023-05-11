class RemoveBar {
    public static void main(String[] args) {
        String s1 = "990925-1012999";
        String s2 = s1.substring(0, 6) + ' ' + s1.substring(7);
        System.out.println(s2);
    }
}

