class SinivelCap {    // Äà¹° Ã³Ä¡¿ë Ä¸½¶
    void take() {
        System.out.println("Äà¹°ÀÌ ½Ï~ ³³´Ï´Ù.");
    }
}

class SneezeCap {    // ÀçÃ¤±â Ã³Ä¡¿ë Ä¸½¶
    void take() {
        System.out.println("ÀçÃ¤±â°¡ ¸Ü½À´Ï´Ù.");
    }
}

class SnuffleCap {    // ÄÚ¸·Èû Ã³Ä¡¿ë Ä¸½¶
    void take() {
        System.out.println("ÄÚ°¡ »½ ¶Õ¸³´Ï´Ù.");
    }
}

class ColdPatient {
    void takeSinivelCap(SinivelCap cap) {
        cap.take();
    }

    void takeSneezeCap(SneezeCap cap) { 
        cap.take();
    }

    void takeSnuffleCap(SnuffleCap cap) {
        cap.take();
    }
}

class BadEncapsulation {
    public static void main(String[] args) {
        ColdPatient suf = new ColdPatient();

        // Äà¹° Ä¸½¶ ±¸¸Å ÈÄ º¹¿ë
        suf.takeSinivelCap(new SinivelCap());
        
        // ÀçÃ¤±â Ä¸½¶ ±¸¸Å ÈÄ º¹¿ë
        suf.takeSneezeCap(new SneezeCap());
        
        // ÄÚ¸·Èû Ä¸½¶ ±¸¸Å ÈÄ º¹¿ë
        suf.takeSnuffleCap(new SnuffleCap());
    }
}