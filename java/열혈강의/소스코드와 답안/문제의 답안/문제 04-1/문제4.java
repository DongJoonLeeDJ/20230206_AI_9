class AddNum {
    public static void main(String[] args) {
        int result = 3 + 6;
        System.out.println("3 + 6 = " + result);
        
        result += 9;
        System.out.println("3 + 6 + 9 = " + result);
        
        result += 12;
        System.out.println("3 + 6 + 9 + 12 = " + result);
    }
}

// 덧셈의 수를 최소화하기 위하여 이전 덧셈 결과를 활용하였다. 