import java.util.Scanner;
import java.util.Random;

class RandomBetween {
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);
        System.out.print("입력1: ");
        int A = keyboard.nextInt();
        
        System.out.print("입력2: ");
        int Z = keyboard.nextInt();

        int min, max; 

        if(A > Z) {
            min = Z;
            max = A;
        } 
        else {
            min = A;
            max = Z;
        }

        Random rand = new Random();
        int rn;
   
        for(int i = 0; i < 10; i++) {
           rn = min;
           rn += rand.nextInt(max - min + 1);
           System.out.println(rn);
        }
    }
}
