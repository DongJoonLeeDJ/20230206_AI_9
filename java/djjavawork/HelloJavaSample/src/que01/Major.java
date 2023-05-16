package que01;

public class Major {
	private int code;
	private String name;
	
	public Major(int code, String name) {
		this.code = code;
		this.name = name;
	}
	public Major(int code) {
		this.code = code;
	}
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
	
	public void showMajor()
	{
		System.out.println("전공코드 : " + code);
		System.out.println("전공명 : " + name);
	}
	
	
}
