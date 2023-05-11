class ArrayMinMax {
    public static int maxValue(int[] arr) {
        int max = arr[0];

        for(int i = 1; i < arr.length; i++) {
            if(max < arr[i])
                max = arr[i];
        }
        
        return max;
    }
    
    public static int minValue(int[] arr) {
        int min = arr[0];
        
        for(int e: arr) {
            if(min > e)
                min = e;
        }
        
        return min;
    }
    
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5, 6, 7};        
        System.out.println("ÃÖ¼Ú°ª: " + minValue(arr));
        System.out.println("ÃÖ´ñ°ª: " + maxValue(arr));
    }
}
