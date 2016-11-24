package com.example.administrator.handler3;

import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private Button button;
    private Handler handler;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        button = (Button)findViewById(R.id.ButtonId);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Message msg = handler.obtainMessage();
                String s = "your app is working!";
                msg.obj = s;
                handler.sendMessage(msg);
            }
        });

        Thread thread = new MyThread();
        thread.start();
    }

    class MyThread extends Thread{
        public void run(){
            Looper.prepare();
            handler = new Handler(){
                public void handleMessage(Message msg) {
                    String s = (String)msg.obj;
                }
            };
            Looper.loop();
        }
    }
}
