class MakeThreadMultiDemo {
    public static void main(String[] args) {
        Runnable task1 = () -> {    // 20 미만 짝수 출력
            try {
                for(int i = 0; i < 20; i++) {
                    if(i % 2 == 0)
                        System.out.print(i + " ");
                    Thread.sleep(100);
                }
            } catch(InterruptedException e) {
                e.printStackTrace();
            }     
        };

        Runnable task2 = () -> {    // 20 미만 홀수 출력
            try {
                for(int i = 0; i < 20; i++) {
                    if(i % 2 == 1)
                        System.out.print(i + " ");
                    Thread.sleep(100);
                }
            } catch(InterruptedException e) {
                e.printStackTrace();
            }     
        };

        Thread t1 = new Thread(task1);
        Thread t2 = new Thread(task2);

        t1.start();
        t2.start();
    }
}