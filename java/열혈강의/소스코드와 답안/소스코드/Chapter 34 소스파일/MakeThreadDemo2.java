class Task extends Thread {
    public void run() {
        int n1 = 10;
        int n2 = 20;
        String name = Thread.currentThread().getName();
        System.out.println(name + ": " + (n1 + n2));    
    }
}

class MakeThreadDemo2 {
    public static void main(String[] args) {
        Task t1 = new Task();
        Task t2 = new Task();
        
        t1.start();
        t2.start();

        System.out.println("End " + Thread.currentThread().getName());
    }
}