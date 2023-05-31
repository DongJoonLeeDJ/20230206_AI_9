package com.javalec.ex.dao;

import java.sql.*;
import java.util.ArrayList;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.sql.DataSource;

import com.javalec.ex.dto.BDto;

public class BDao {
	private DataSource ds;
	private Connection conn = null;
	private PreparedStatement pstmt = null;
	private ResultSet rs = null;
	
	public BDao() {
		try {
			Context ctx = new InitialContext();
			ds = (DataSource)ctx.lookup
					("java:comp/env/jdbc/mysql");
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public ArrayList<BDto> list() {
		ArrayList<BDto> dtos = new ArrayList<BDto>();
		try {
			String sql = "select bId, bName, bTitle,"
					+"bContent, bDate, bHit,"
					+ "bGroup, bStep, bIndent from "
					+ " mvc_board order by bGroup desc,"
					+ "bStep asc";
			//최신 글이 맨 위에 올라오고, 답글은 가장 먼저 단 게 위로 올라가게 함
			System.out.println(sql);
			conn=ds.getConnection();
			pstmt = conn.prepareStatement(sql);
			rs=pstmt.executeQuery();
			while(rs.next()) {
				int bId = rs.getInt("bId");
				String bName = rs.getString("bName");
				String bTitle = rs.getString("bTitle");
				String bContent = rs.getString("bContent");
				Timestamp bDate = rs.getTimestamp("bDate");
				int bHit = rs.getInt("bHit");
				int bGroup = rs.getInt("bGroup");
				int bStep = rs.getInt("bStep");
				int bIndent = rs.getInt("bIndent");
				BDto dto = new BDto(bId, bName, bTitle, bContent, bDate, bHit, bGroup, bStep, bIndent);
				dtos.add(dto);
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				rs.close();
				pstmt.close();
				conn.close();
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		return dtos;
	}

	public BDto contentView(String bId) {
		upHit(bId); //해당 글을 클릭했으므로 조회수를 상승시켜야 함
		BDto dto = null;
		try {
			conn = ds.getConnection();
			String sql = "select * from mvc_board where bId=?";
			pstmt = conn.prepareStatement(sql);
			pstmt.setInt(1,Integer.parseInt(bId));
			rs=pstmt.executeQuery();
			if(rs.next()) {
				int myId = rs.getInt("bId");
				String bName = rs.getString("bName");
				String bTitle = rs.getString("bTitle");
				String bContent = rs.getString("bContent");
				Timestamp bDate = rs.getTimestamp("bDate");
				int bHit = rs.getInt("bHit");
				int bGroup = rs.getInt("bGroup");
				int bStep = rs.getInt("bStep");
				int bIndent = rs.getInt("bIndent");
				dto = new BDto(myId, bName, bTitle, bContent, bDate, bHit, bGroup, bStep, bIndent);
			}
			
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				rs.close();
				pstmt.close();
				conn.close();
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
		return dto;
	}

	private void upHit(String bId) {
		try {
			conn = ds.getConnection();
			String sql = "update mvc_board set bHit=bHit+1 where bId=?";
			pstmt = conn.prepareStatement(sql);
			pstmt.setString(1, bId);
			pstmt.executeUpdate();
		} catch (Exception e) {
			e.printStackTrace();
		}finally {
			try {
				pstmt.close();
				conn.close();
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
		
	}

	public void modify(String bId, String bName, 
			String bTitle, String bContent) {
		try {
			conn = ds.getConnection();
			String sql = "update mvc_board set bName=?, bTitle=?,"
					+ "bContent=? where bId=?";
			pstmt = conn.prepareStatement(sql);
			pstmt.setString(1,bName);
			pstmt.setString(2,bTitle);
			pstmt.setString(3,bContent);
			pstmt.setString(4,bId);
			pstmt.executeUpdate();
		}catch (Exception e) {
			e.printStackTrace();
		}finally {
			try {
				pstmt.close();
				conn.close();
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
		
	}

	public void write(String bName, String bTitle, 
			String bContent) {
		try {
			conn = ds.getConnection();
			String sql = "insert into mvc_board("
					+ "bId, bName, bTitle, bContent, bHit,"
					+ "bGroup, bStep, bIndent) values "
					+ "(nextval('mvc_board'),?,?,?,0,"
					+ "currval('mvc_board'),0,0)";
			pstmt = conn.prepareStatement(sql);
			pstmt.setString(1,bName);
			pstmt.setString(2,bTitle);
			pstmt.setString(3,bContent);
			pstmt.executeUpdate();
		}catch (Exception e) {
			e.printStackTrace();
		}finally {
			try {
				pstmt.close();
				conn.close();
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
		
		
	}

	public void delete(String bId) {
		try {
			conn = ds.getConnection();
			String sql = "delete from mvc_board where bId=?";
			pstmt = conn.prepareStatement(sql);
			pstmt.setString(1,bId);
			pstmt.executeUpdate();
		}catch (Exception e) {
			e.printStackTrace();
		}finally {
			try {
				pstmt.close();
				conn.close();
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
		
		
	}

	public BDto reply_view(String bId) {
		BDto dto = null;
		try {
			conn = ds.getConnection();
			String sql = "select * from mvc_board where bId=?";
			pstmt = conn.prepareStatement(sql);
			pstmt.setInt(1,Integer.parseInt(bId));
			rs=pstmt.executeQuery();
			if(rs.next()) {
				int myId = rs.getInt("bId");
				String bName = rs.getString("bName");
				String bTitle = rs.getString("bTitle");
				String bContent = rs.getString("bContent");
				Timestamp bDate = rs.getTimestamp("bDate");
				int bHit = rs.getInt("bHit");
				int bGroup = rs.getInt("bGroup");
				int bStep = rs.getInt("bStep");
				int bIndent = rs.getInt("bIndent");
				dto = new BDto(myId, bName, bTitle, bContent, bDate, bHit, bGroup, bStep, bIndent);
			}
			
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				rs.close();
				pstmt.close();
				conn.close();
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
		return dto;
	}

	public void reply(String bId, String bName, String bTitle, String bContent, String bGroup, String bStep,
			String bIndent) {
		
		replyShape(bGroup, bStep);
		
		try {
			conn = ds.getConnection();
			String sql = "insert into mvc_board("
					+ "bId, bName, bTitle, bContent, "
					+ "bGroup, bStep, bIndent) values "
					+ "(nextval('mvc_board'),?,?,?,?,"
					+ "?,?)";
			pstmt = conn.prepareStatement(sql);
			pstmt.setString(1,bName);
			pstmt.setString(2,bTitle);
			pstmt.setString(3,bContent);
			pstmt.setInt(4,Integer.parseInt(bGroup));
			pstmt.setInt(5,Integer.parseInt(bStep)+1);
			pstmt.setInt(6,Integer.parseInt(bIndent)+1);
			pstmt.executeUpdate();
		}catch (Exception e) {
			e.printStackTrace();
		}finally {
			try {
				pstmt.close();
				conn.close();
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
		
	}

	private void replyShape(String bGroup, String bStep) {

		try {
			conn = ds.getConnection();
			String sql = "update mvc_board set bStep=bStep+1 where "
					+ "bGroup=? and bStep>?";
			pstmt = conn.prepareStatement(sql);
			pstmt.setInt(1, Integer.parseInt(bGroup));
			pstmt.setInt(2, Integer.parseInt(bStep));
			pstmt.executeUpdate();
		} catch (Exception e) {
			e.printStackTrace();
		}finally {
			try {
				pstmt.close();
				conn.close();
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
		
		
	}
}







