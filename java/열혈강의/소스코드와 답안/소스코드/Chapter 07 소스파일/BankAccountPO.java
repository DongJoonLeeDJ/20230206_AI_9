class BankAccountPO {
    static int balance = 0;     // ¿¹±Ý ÀÜ¾×

    public static void main(String[] args) {
        deposit(10000);
        checkMyBalance();
        
        withdraw(3000);
        checkMyBalance(); 
    }

    public static int deposit(int amount) {
        balance += amount;
        return balance;
    }    

    public static int withdraw(int amount) {
        balance -= amount;
        return balance;
    }

    public static int checkMyBalance() {
        System.out.println("ÀÜ¾× : " + balance);
        return balance;
    }

}
	
