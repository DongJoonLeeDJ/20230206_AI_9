class MobilePhone {
    protected String number;
    
    public MobilePhone(String num) {
        number = num;
    }
    
    public void answer() {
        System.out.println("Hi~ from " + number);
    }
}

class SmartPhone extends MobilePhone { 
    private String androidVer;
    
    public SmartPhone(String num, String ver) {
        super(num);
        androidVer = ver;
    }
    
    public void playApp() {
        System.out.println("App is running in " + androidVer);
    }
}


class MobileSmartPhone {
    public static void main(String[] args) {
        // 스마트 폰을 하나 생성
        SmartPhone phone = new SmartPhone("010-555-777", "Nougat");
        
        // 전화를 받는다. 
        phone.answer();
        
        // 앱을 선택하고 실행한다.
        phone.playApp();    
    }
}