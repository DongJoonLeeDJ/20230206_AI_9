package studyjava01_abstract;

public abstract class LolChamp {
	private String Name;
	private String Runeterra; //�Ҽ�
	//alt shift s ������ r Ű
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
	
	//LOL è����� �翬�� Q W E R ����� ������ �Ǿ� �־�� �Ѵ�.
	public abstract void Q();
	public abstract void W();
	public abstract void E();
	public abstract void R();
	
}










