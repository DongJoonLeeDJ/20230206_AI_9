package com.javalec.ex;

import java.sql.*;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.sql.DataSource;

public class Dao {
	private Connection conn = null;
	private Statement stmt = null;
	private ResultSet rs = null;
	private PreparedStatement pstmt = null;
	
	private DataSource ds = null;
	
	public Dao() {
		try {
			Context ctx = new InitialContext();
			ds = (DataSource)ctx.lookup("java:comp/env/jdbc/mysql");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public int InsertStudent(String beonho, String name) {
		int result = 0;
		conn = null;
		pstmt = null;
		try {
			conn = ds.getConnection(); //DB¿¬°á ³¡
			String query = "insert into student values(?,?)";
			pstmt = conn.prepareStatement(query);
			pstmt.setString(1, beonho);
			pstmt.setString(2, name);
			result = pstmt.executeUpdate();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				pstmt.close();
				conn.close();
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
		return result;
	}
	

}










