package studyjava02_abstract;

public abstract class Teacher {
	private String name;
	private String Major;
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getMajor() {
		return Major;
	}
	public void setMajor(String major) {
		Major = major;
	}
	public abstract void Teach();
}
