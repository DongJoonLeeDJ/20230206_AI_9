import java.util.Scanner;

class ReadAgeException extends Exception {
    public ReadAgeException() {
        super("유효하지 않은 나이가 입력되었습니다.");
    }
}

class MyExceptionClass {
    public static void main(String[] args) {
        System.out.print("나이 입력: ");
    
        try {
            int age = readAge();
            System.out.printf("입력된 나이: %d \n", age);
        }
        catch(ReadAgeException e) {
            System.out.println(e.getMessage());
        }
    }
    
    public static int readAge() throws ReadAgeException {
        Scanner kb = new Scanner(System.in);
        int age = kb.nextInt();
        
        if(age < 0)
            throw new ReadAgeException();

        return age;
    }
}