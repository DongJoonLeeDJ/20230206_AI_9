package studyjava03_helloDB;

//import java.sql.Connection;//F2 눌러서 Import할 것
/*
 * import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
 * */
import java.sql.*;

public class StudyJava03_WelcomeDB {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//js,C#에도 있는 문법
		//try 안에 있는 걸 실행하는 데,
		//에러가 나면  catch부분으로 빠지고
		//그게 아니면 catch는 무시한다.
		//이걸 하는 이유는 프로그램이 갑자기 종료되는 걸 방지하기 위함
		//ex int a = 10; int b =0; int c = a/b; //에러!
		//try catch가 없으면 그냥 종료되지만
		//try catch를 걸어주면 catch부분에 있는 코드만 실행하고
		//프로그램이 다음 단계로 진행됨
//		System.out.println("Hi");
//		try {
//			int a  = 10;
//			int b  =0;
//			int c = a/b; //오류
//		} catch (Exception e) {
//			// TODO: handle exception
//			e.printStackTrace();
//		}
//		System.out.println("안녕");
		Connection con = null;
		try {
			Class.forName("org.sqlite.JDBC");//jar 파일에 들어있는 클래스를 찾음
			String dbFile = "D:\\shareFolder\\java\\HelloDB.db";
			con = DriverManager.getConnection("jdbc:sqlite:"+dbFile);
			
			Statement stat = con.createStatement();
			ResultSet rs = stat.executeQuery("select * from TempTable");
			while(rs.next()) {
				System.out.println(rs.getInt(1));//컬럼명 적거나 인덱스 적는 데, 인덱스가 1부터 시작함
				System.out.println(rs.getString("Field2"));
				System.out.println(rs.getString("Field3"));
			}
			
			//데이터 삽입
			String sql = String.format
					("insert into TempTable values(%d, %d, %d)",
					100,200,300);
			stat.execute(sql);//insert, update, delete에서 많이 쓰임
			//executeQuery는 select에서 주로 쓰임
			//delete문이랑 update문은 이거랑 똑같이 쓰면 된다.
			
			
		} catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
		} finally { //DB 작업 다 끝나고 나면 DB 연결을 해제해줘야 함
			//finally : 마침내
			//catch에서 return; 이렇게 호출하면서
			//함수 자체가 끝나도
			//finally에 있는 건 무조건 실행하고 끝남
			//그래서 DB 연결 해제할 때 많이 쓰임
			try {
				con.close();
			} catch (Exception e2) {
				// TODO: handle exception
			}
		}

	}

}












