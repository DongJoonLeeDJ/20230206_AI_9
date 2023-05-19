package studyjava01_abstract;

public abstract class LolChamp {
	private String Name;
	private String Runeterra; //소속
	//alt shift s 누르고 r 키
	public String getName() {
		return Name;
	}
	public void setName(String name) {
		Name = name;
	}
	public String getRuneterra() {
		return Runeterra;
	}
	public void setRuneterra(String runeterra) {
		Runeterra = runeterra;
	}
	
	//LOL 챔프라면 당연히 Q W E R 기능이 구현이 되어 있어야 한다.
	public abstract void Q();
	public abstract void W();
	public abstract void E();
	public abstract void R();
	
}










