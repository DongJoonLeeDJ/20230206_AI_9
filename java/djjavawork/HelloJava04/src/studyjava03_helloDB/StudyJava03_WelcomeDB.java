package studyjava03_helloDB;

//import java.sql.Connection;//F2 ������ Import�� ��
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
		
		//js,C#���� �ִ� ����
		//try �ȿ� �ִ� �� �����ϴ� ��,
		//������ ����  catch�κ����� ������
		//�װ� �ƴϸ� catch�� �����Ѵ�.
		//�̰� �ϴ� ������ ���α׷��� ���ڱ� ����Ǵ� �� �����ϱ� ����
		//ex int a = 10; int b =0; int c = a/b; //����!
		//try catch�� ������ �׳� ���������
		//try catch�� �ɾ��ָ� catch�κп� �ִ� �ڵ常 �����ϰ�
		//���α׷��� ���� �ܰ�� �����
//		System.out.println("Hi");
//		try {
//			int a  = 10;
//			int b  =0;
//			int c = a/b; //����
//		} catch (Exception e) {
//			// TODO: handle exception
//			e.printStackTrace();
//		}
//		System.out.println("�ȳ�");
		Connection con = null;
		try {
			Class.forName("org.sqlite.JDBC");//jar ���Ͽ� ����ִ� Ŭ������ ã��
			String dbFile = "D:\\shareFolder\\java\\HelloDB.db";
			con = DriverManager.getConnection("jdbc:sqlite:"+dbFile);
			
			Statement stat = con.createStatement();
			ResultSet rs = stat.executeQuery("select * from TempTable");
			while(rs.next()) {
				System.out.println(rs.getInt(1));//�÷��� ���ų� �ε��� ���� ��, �ε����� 1���� ������
				System.out.println(rs.getString("Field2"));
				System.out.println(rs.getString("Field3"));
			}
			
			//������ ����
			String sql = String.format
					("insert into TempTable values(%d, %d, %d)",
					100,200,300);
			stat.execute(sql);//insert, update, delete���� ���� ����
			//executeQuery�� select���� �ַ� ����
			//delete���̶� update���� �̰Ŷ� �Ȱ��� ���� �ȴ�.
			
			
		} catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
		} finally { //DB �۾� �� ������ ���� DB ������ ��������� ��
			//finally : ��ħ��
			//catch���� return; �̷��� ȣ���ϸ鼭
			//�Լ� ��ü�� ������
			//finally�� �ִ� �� ������ �����ϰ� ����
			//�׷��� DB ���� ������ �� ���� ����
			try {
				con.close();
			} catch (Exception e2) {
				// TODO: handle exception
			}
		}

	}

}












