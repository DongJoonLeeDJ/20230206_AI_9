package que02;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

import que01.Major;
import que01.Student;

public class DBConnector {
	
	
	static void selectQuery(String tableName, int PK, boolean isJoin) {

		Connection con = null;
		try {
			Class.forName("org.sqlite.JDBC");//jar 파일에 들어있는 클래스를 찾음
			String dbFile = "D:\\shareFolder\\java\\HelloDB.db";
			con = DriverManager.getConnection("jdbc:sqlite:"+dbFile);
			
			Statement stat = con.createStatement();
			ResultSet rs = null;

			if(isJoin)
			{
				rs = stat.executeQuery("select Student.code, Student.name, Major.name from Student join Major on Student.majcode=Major.code");
			}
			else
			{

				if(PK!=-1)
				{
					//System.out.println("select * from "+tableName+" where code="+PK);
					//rs = stat.executeQuery("select * from " + tableName);
					rs = stat.executeQuery("select * from "+tableName+" where code="+PK);	
				}
				else
					rs = stat.executeQuery("select * from " + tableName);
			}
			if(isJoin)
			{
				while(rs.next()) {
					System.out.print(rs.getInt(1)+"\t");//컬럼명 적거나 인덱스 적는 데, 인덱스가 1부터 시작함
					System.out.print(rs.getString(2)+"\t"); //문자열 형태 출력이라면 getString해야 한다.
					System.out.print(rs.getString(3));
					System.out.println();
				}	
			}
			else
			{
				while(rs.next()) {
					System.out.print(rs.getInt(1)+"\t");//컬럼명 적거나 인덱스 적는 데, 인덱스가 1부터 시작함
					System.out.print(rs.getString(2)+"\t"); //문자열 형태 출력이라면 getString해야 한다.
					if(tableName.equals("Student"))
						System.out.print(rs.getInt(3));
					System.out.println();
				}
			}
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
				e2.printStackTrace();
			}
		}
	}
	static void doQuery(String Query, Student s, Major m) {

		Connection con = null;
		try {
			Class.forName("org.sqlite.JDBC");//jar 파일에 들어있는 클래스를 찾음
			String dbFile = "D:\\shareFolder\\java\\HelloDB.db";
			con = DriverManager.getConnection("jdbc:sqlite:"+dbFile);
			
			Statement stat = con.createStatement();
			String sql = null;
			switch (Query) {
			case "insert":
				if(s!=null)
				{
					sql = String.format
							("insert into Student values(%d, '%s', %d)",
							s.getCode(),s.getName(),s.getMajCode());
				}
				else if(m!=null)
				{

					sql = String.format
							("insert into Major values(%d, '%s')",
							m.getCode(),m.getName());
				}
				else
				{
					System.out.println("잘못된 입력입니다.(insert)");
					return;
				}
				break;
			case "update":
				if(s!=null)
				{
					sql = String.format
							("update Student set name='%s', majcode=%d where code=%d",
							s.getName(),s.getMajCode(),s.getCode());
				}
				else if(m!=null)
				{

					sql = String.format
							("update Major set name='%s' where code=%d",
									m.getName(), m.getCode());
				}
				else
				{
					System.out.println("잘못된 입력입니다.(update)");
					return;
				}
				
				break;
			case "delete":
				if(s!=null)
				{
					sql = String.format
							("delete from Student where code=%d", s.getCode());
				}
				else if(m!=null)
				{

					sql = String.format
							("delete from Major where code=%d", m.getCode());
				}
				else
				{
					System.out.println("잘못된 입력입니다.(delete)");
					return;
				}
				
				break;
			default:
				break;
			}
			
			
			//데이터 삽입
			System.out.println(sql);
			stat.executeUpdate("PRAGMA foreign_keys = ON;");
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
				e2.printStackTrace();
			}
		}
	}
	
	
}
