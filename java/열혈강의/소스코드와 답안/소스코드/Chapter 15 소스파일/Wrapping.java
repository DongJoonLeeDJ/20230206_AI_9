class Box {
    public void simpleWrap() { 
        System.out.println("Simple Wrapping");
    }
}

class PaperBox extends Box {
    public void paperWrap() {
        System.out.println("Paper Wrapping");
    }
}

class GoldPaperBox extends PaperBox {
    public void goldWrap() {
        System.out.println("Gold Wrapping");
    }
}

class Wrapping {
    public static void main(String[] args) {
        Box box1 = new Box();
        PaperBox box2 = new PaperBox();
        GoldPaperBox box3 = new GoldPaperBox();
        
        wrapBox(box1);
        wrapBox(box2);
        wrapBox(box3);
    }

    public static void wrapBox(Box box) {
        if(box instanceof GoldPaperBox) {
            ((GoldPaperBox)box).goldWrap();
        }
        else if(box instanceof PaperBox) {
            ((PaperBox)box).paperWrap();
        }
        else {
            box.simpleWrap();
        }
    }
}