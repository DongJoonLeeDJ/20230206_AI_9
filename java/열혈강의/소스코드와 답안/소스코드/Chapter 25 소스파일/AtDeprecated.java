interface Viewable {
    @Deprecated
    public void showIt(String str);

    public void brShowIt(String str);
}

class Viewer implements Viewable {
    @Override 
    public void showIt(String str) {
        System.out.println(str);
    }

    @Override
    public void brShowIt(String str) {
        System.out.println('[' + str + ']');
    }
}

class AtDeprecated {
    public static void main(String[] args) {
        Viewable view = new Viewer();
        view.showIt("Hello Annotations");
        view.brShowIt("Hello Annotations");
    }
}
