import java.nio.ByteBuffer;

class BufferPositionCheck {
    public static void main(String[] args) {
        ByteBuffer bb = ByteBuffer.allocate(1024);
        System.out.println("Position: " + bb.position());
        bb.putInt(120);
        System.out.println("Position: " + bb.position());
        bb.putDouble(0.94);
        System.out.println("Position: " + bb.position());
        bb.flip();
        System.out.println("Position: " + bb.position());
        int n = bb.getInt();
        System.out.println("Position: " + bb.position());
        double d = bb.getDouble();
        System.out.println("Position: " + bb.position());
    }
}