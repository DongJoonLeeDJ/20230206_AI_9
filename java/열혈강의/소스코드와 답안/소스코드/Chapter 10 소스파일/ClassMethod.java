class NumberPrinter {
    private int myNum = 0;

    static void showInt(int n){ 
        System.out.println(n); 
    }
    
    static void showDouble(double n) { 
        System.out.println(n); 
    }

    void setMyNumber(int n) {
        myNum = n;
    }

    void showMyNumber() {
        showInt(myNum);
    }    
}

class ClassMethod {
    public static void main(String[] args) {
        NumberPrinter.showInt(20);
        NumberPrinter np = new NumberPrinter();
        np.showDouble(3.15);
    
        np.setMyNumber(75);
        np.showMyNumber();
    }
}