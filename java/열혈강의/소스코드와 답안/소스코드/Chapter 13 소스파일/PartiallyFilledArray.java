class PartiallyFilledArray {
    public static void main(String[] args) {
        int[][] arr = {
            {11},
            {22, 33},
            {44, 55, 66}
        };


        // 배열의 구조대로 내용 출력
        for(int i = 0; i < arr.length; i++) {
            for(int j = 0; j < arr[i].length; j++) {
                System.out.print(arr[i][j] + "\t");
            }
            System.out.println();
        }
    }
}