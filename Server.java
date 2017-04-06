import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] args) {
        while(true){
            try {
                //创建服务器端套接字，接受来自客户端的连接请求
                ServerSocket ss=new ServerSocket(9999);
                Socket s=ss.accept();

                //获取客户端套接字的输出流
                OutputStream os=s.getOutputStream();
                DataOutputStream dos=new DataOutputStream(os);

                //获取客户端输入流
                InputStream is=s.getInputStream();
                DataInputStream dis=new DataInputStream(is);

                //创建字符输入流接受键盘输入
                InputStreamReader isr=new InputStreamReader(System.in);
                BufferedReader br=new BufferedReader(isr);

                dos.writeUTF("You connect successfully!");
                dis.close();
                dos.close();
                ss.close();
                s.close();

            } catch (Exception e) {
                // TODO: handle exception
                e.printStackTrace();
            }
        }
    }
}
