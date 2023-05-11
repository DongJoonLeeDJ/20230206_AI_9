class BankAccount {
    int balance = 0;     // ¿¹±Ý ÀÜ¾×

    public int deposit(int amount) {
        balance += amount;
        return balance;
    }    

    public int withdraw(int amount) {
        balance -= amount;
        return balance;
    }

    public int checkMyBalance() {
        System.out.println("ÀÜ¾× : " + balance);
        return balance;
    }
}
	

class PassingRef {
    public static void main(String[] args) {
        BankAccount ref = new BankAccount();

        ref.deposit(3000);
        ref.withdraw(300);

        check(ref);
    }

    public static void check(BankAccount acc) {
        acc.checkMyBalance();
    }
}