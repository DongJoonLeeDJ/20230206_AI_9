package studyjava04_interface_abstract;

public abstract class Digimon {
	private String name;
	private int level;
	public abstract void evolution();//ÁøÈ­
	public abstract void degeneration();//ÅğÈ­
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getLevel() {
		return level;
	}
	public void setLevel(int level) {
		this.level = level;
	}
	

}
