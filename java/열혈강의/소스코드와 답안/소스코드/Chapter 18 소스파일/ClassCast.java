class Board { }
class PBoard extends Board { }

class ClassCast { 
    public static void main(String[] args) {
         Board pbd1 = new PBoard();
         PBoard pbd2 = (PBoard)pbd1;    // OK!
    
         System.out.println(".. intermediate location .. ");
         Board ebd1 = new Board();
         PBoard ebd2 = (PBoard)ebd1;    // Exception!
    }
}