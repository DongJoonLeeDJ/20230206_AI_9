interface SMaker {
    String make(char[] ar);
}

class StringMaker {
    public static String chsToString(char[] a, SMaker m) {
        return m.make(a);
    }

    public static void main(String[] args) {
        SMaker sm = (ar) -> {
            return new String(ar);
        };
        
        char[] src = {'R', 'o', 'b', 'o', 't'};        
        String str = chsToString(src, sm);
        System.out.println(str);
    }
}