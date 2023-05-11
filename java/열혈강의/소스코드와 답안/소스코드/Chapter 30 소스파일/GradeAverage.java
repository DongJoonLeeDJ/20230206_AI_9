import java.util.Arrays;
import java.util.stream.Stream;
import java.util.stream.IntStream;

class ReportCard {
    private int kor;    // 국어 점수
    private int eng;    // 영어 점수
    private int math;    // 수학 점수
    
    public ReportCard(int k, int e, int m) {
        kor = k;
        eng = e;
        math = m;    
    }
    public int getKor() { return kor; }
    public int getEng() { return eng; }
    public int getMath() { return math; }
}


class GradeAverage {
    public static void main(String[] args) {
        ReportCard[] cards = {
            new ReportCard(70, 80, 90),
            new ReportCard(90, 80, 70),
            new ReportCard(80, 80, 80)
        };       

        Stream<ReportCard> sr = Arrays.stream(cards);

        IntStream si = sr.flatMapToInt(
               r -> IntStream.of(r.getKor(), r.getEng(), r.getMath()));

        double avg = si.average().getAsDouble();
        System.out.println("avg. " + avg);
     }
}