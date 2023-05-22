package studyjava01_creator;

public class Dragon extends Cryptid{

	@Override
	public void Fly() {
		System.out.println("Äõ¿ì¿ö µå·¡°ï½º·´°Ô ³­´Ù.");
		
	}

	@Override
	public void FlapWing() {
		System.out.println("³¯°³ ÆÛ´öÆÛ´ö µå·¡°ïµå·¡°ï.");
		
	}

	@Override
	public void Run() {
		return; //¶×¶×ÇØ¼­ ¸ø ¶Ú´Ù.
		
	}

	@Override
	public void jog() {
		return; //°ÈÁöµµ ¾Ê´Â´Ù.
		
	}

	@Override
	public void sleep() {
		System.out.println("ÇÑ ¹ø ÄÚ °ñ¶§¸¶´Ù µµ½Ã ÇÏ³ª ¸ê¸Á~");
		
	}

}
