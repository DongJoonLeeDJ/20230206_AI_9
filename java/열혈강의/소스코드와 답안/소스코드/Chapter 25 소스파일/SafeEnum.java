enum Animal { DOG, CAT }

enum Person { MAN, WOMAN }

class SafeEnum {
    public static void main(String[] args) {
        System.out.println(Animal.DOG);
        // 정상적인 메소드 호출
        who(Person.MAN);

        // 비정상적 메소드 호출
//	who(Animal.DOG);
    }
	
    public static void who(Person man) {
        switch(man) {
        case MAN:
            System.out.println("남성 손님입니다.");
            break;
        case WOMAN:
            System.out.println("여성 손님입니다.");
            break;
        }
    }
}
