class ShiftArray {
    public static void shiftTwoDArr(int[][] arr) {
        int[] lastLow = arr[arr.length - 1];

        for(int low = arr.length - 1; low > 0; low--)
            arr[low] = arr[low - 1];
        
        arr[0] = lastLow;
    }
    
    public static void showTwoDArr(int[][] arr) {
        for(int i = 0; i < arr.length; i++) {
            for(int j = 0; j < arr[i].length; j++)
                System.out.print(arr[i][j] + " ");

            System.out.println();
        }
    }
    
    public static void main(String[] args) {
        int[][] arr = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        System.out.println("1Â÷ shift...");
        shiftTwoDArr(arr);
        showTwoDArr(arr);
        
        System.out.println("2Â÷ shift...");
        shiftTwoDArr(arr);
        showTwoDArr(arr);

        System.out.println("3Â÷ shift...");
	shiftTwoDArr(arr);
	showTwoDArr(arr);
    }
}
