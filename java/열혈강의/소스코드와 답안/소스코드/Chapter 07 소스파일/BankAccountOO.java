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
	

class BankAccountOO {
    public static void main(String[] args) {
        BankAccount yoon = new BankAccount();
        BankAccount park = new BankAccount();

        yoon.deposit(5000);
        park.deposit(3000);

        yoon.withdraw(2000);
        park.withdraw(2000);

        yoon.checkMyBalance();
        park.checkMyBalance();  
    }
}