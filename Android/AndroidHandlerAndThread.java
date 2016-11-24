package com.example.administrator.handler2;

import android.os.Handler;
import android.os.Message;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private Button button;
    private TextView textView;
    private Handler handler;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        button = (Button)findViewById(R.id.ButtonId);
        textView = (TextView)findViewById(R.id.TextViewId);

        handler = new MyHandler();

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Thread thread = new NetWorkThread();
                thread.start();
            }
        });
    }

    class MyHandler extends Handler {
        @Override
        public void handleMessage(Message msg){
            String s = (String)msg.obj;
            textView.setText(s);
        }
    }

    class NetWorkThread extends Thread{
        @Override
        public void run(){
            try {
                Thread.sleep(2 * 1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            String s = "your app is working!";
            Message msg = handler.obtainMessage();
            msg.obj = s;
            handler.sendMessage(msg);
        }
    }
}
