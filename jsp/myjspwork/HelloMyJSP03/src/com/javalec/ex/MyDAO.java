package com.javalec.ex;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;

//DAO : Data Access Object => DB연결에 필요한 정보를 모아둔 객체
public class MyDAO {
	private String url =
			"jdbc:mysql://localhost:3306/myjsp?"+
			"useUnicode=true&characterEncoding=utf8&"+
			"serverTimezone=UTC";
	private String uid = "root";
	private String upw = "1234";
	
	private Connection conn = null;
	private Statement stmt = null;
	private ResultSet rs = null;
	private PreparedStatement pstmt =null;
	
	
	public MyDAO() {
		try {
			//jar랑 연결
			Class.forName("com.mysql.cj.jdbc.Driver");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public ArrayList<String> showMembers() {
		ArrayList<String> results = new ArrayList<String>();
		conn = null;
		stmt = null;
		try {
			conn = DriverManager.getConnection(url,uid,upw);
			stmt = conn.createStatement();
			rs = stmt.executeQuery("select * from djemployee");
			while(rs.next()) {
				String result = "";
				result +=rs.getString("name")+",";
				result +=rs.getString("sabeon")+",";
				result +=rs.getString("buseo");
				results.add(result);
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				rs.close();
				stmt.close();
				conn.close();
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
		return results;
	}
	

}
