import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.InputStreamReader;
import java.net.Socket;

public class Client {
    public static void main(String[] args) {
        try {
            Socket sc = new Socket("localhost",9999);

			InputStream is = sc.getInputStream();
            DataInputStream dis = new DataInputStream(is);

            OutputStream os = sc.getOutputStream();
            DataOutputStream dos = new DataOutputStream(os);

            InputStreamReader isr = new InputStreamReader(System.in);
            BufferedReader br = new BufferedReader(isr);

            String message;
            message = dis.readUTF();
            System.out.println(message);
            dis.close();
            dos.close();
            sc.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
