package que01;

public class Student {
	private int code;
	private String name;
	private int majCode;
	public int getCode() {
		return code;
	}
	public void setCode(int code) {
		this.code = code;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getMajCode() {
		return majCode;
	}
	public void setMajCode(int majCode) {
		this.majCode = majCode;
	}
	
	public Student(int code, String name, int majCode) {
		this.code = code;
		this.name = name;
		this.majCode = majCode;
	}
	public Student(int code)
	{
		this.code=code;
	}
	public void showStudent()
	{
		System.out.println("학번 : " + code);
		System.out.println("학생 이름 : " + name);
		System.out.println("학과 코드 명 : " + majCode);
	}
	

}
