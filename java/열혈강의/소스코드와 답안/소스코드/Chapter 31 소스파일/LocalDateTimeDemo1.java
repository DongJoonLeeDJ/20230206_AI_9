import java.time.LocalDateTime;

class LocalDateTimeDemo1 {
    public static void main(String[] args) {
        // 현재 날짜와 시각
        LocalDateTime dt = LocalDateTime.now();
        System.out.println(dt);

        // 영국 바이어와 22시간 35분 뒤 화상 미팅 예정
        LocalDateTime mt = dt.plusHours(22);
        mt = mt.plusMinutes(35);

        // 영국 바이어와 화상 미팅 날짜와 시각
        System.out.println(mt);
    }
}
