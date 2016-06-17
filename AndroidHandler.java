package com.example.administrator.handler;

import android.os.Handler;
import android.os.Message;
import android.provider.Settings;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    private Button button;
    private Handler handler;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        button = (Button)findViewById(R.id.Button);
        button.setOnClickListener(new ButtonListener());
    }

    class ButtonListener implements View.OnClickListener{
        @Override
        public void onClick(View view){
            Message message = handler.obtainMessage();
            message.what = 2;
            handler.sendMessage(message);
        }
    }

    class FirstHandler extends Handler{
        @Override
        public void handleMessage(Message message){
            int what = message.what;
            System.out.println("what = " + what);
        }
    }
}
