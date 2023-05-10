class BitSearch {
    public static void main(String[] args) {
        int num = 15678;
        System.out.println((num>>2) & 1);
        System.out.println( (num>>4) & 1);
    }
}

/*
    위 코드의 기본 원리는 이렇다. 
    확인하고자 하는 비트를 오른쪽 끝으로 보낸다. 
    그리고 이어서 & 연산을 통해 1인지 0인지 확인한다. 
*/
