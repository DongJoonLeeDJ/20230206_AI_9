import java.time.Duration;
import java.time.LocalDateTime;
import java.time.Month;

class DurationDemo {
    public static void main(String[] args) {
        LocalDateTime dt1 = LocalDateTime.of(2020, Month.JANUARY, 12, 15, 30);
        LocalDateTime dt2 = LocalDateTime.of(2020, Month.FEBRUARY, 12, 15, 30);
  
        LocalDateTime dt3 = LocalDateTime.of(2020, Month.JANUARY, 12, 15, 30);
        LocalDateTime dt4 = LocalDateTime.of(2020, Month.FEBRUARY, 13, 14, 29);

        Duration drDate1 = Duration.between(dt1, dt2);
        System.out.println(drDate1);

        Duration drDate2 = Duration.between(dt3, dt4);
        System.out.println(drDate2);
    }
}