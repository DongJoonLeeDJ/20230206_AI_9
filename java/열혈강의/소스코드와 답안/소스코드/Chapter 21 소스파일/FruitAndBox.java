class Apple {
    public String toString() {
        return "I am an apple.";
    }    
}

class Orange {
    public String toString() {
        return "I am an orange.";
    }
}

class AppleBox {
    private Apple ap;

    public void set(Apple a) {
        ap = a;
    }

    public Apple get() {
        return ap;
    }
}


class OrangeBox {
    private Orange or;

    public void set(Orange o) {
        or = o;
    }

    public Orange get() {
        return or;
    }
}


class FruitAndBox {
    public static void main(String[] args) {
        // 과일 담는 박스 생성
        AppleBox aBox = new AppleBox();
        OrangeBox oBox = new OrangeBox();

        // 과일을 박스에 담는다. 
        aBox.set(new Apple());
        oBox.set(new Orange());

        // 박스에서 과일을 꺼낸다.
        Apple ap = aBox.get();
        Orange og = oBox.get();

        System.out.println(ap);
        System.out.println(og);
    }
}