interface Printable {
    void print(String doc);
    default void printCMYK(String doc) {}
}

class Prn731Drv implements Printable {
    @Override
    public void print(String doc) {
        System.out.println("From MD-731 printer");
        System.out.println(doc);
    }
}

class Prn909Drv implements Printable {
    @Override
    public void print(String doc) {
        System.out.println("From MD-909 black & white ver");
        System.out.println(doc);
    }
    
    @Override
    public void printCMYK(String doc) {
        System.out.println("From MD-909 CMYK ver");
        System.out.println(doc);
    }
}

class PrinterDriver4 {
    public static void main(String[] args) {
        String myDoc = "This is a report about...";
    
        Printable prn1 = new Prn731Drv();
        prn1.print(myDoc);

        System.out.println();

        Printable prn2 = new Prn909Drv();
        prn2.print(myDoc);
    }
}