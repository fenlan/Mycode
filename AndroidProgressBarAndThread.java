package com.example.administrator.prograssbarandthread;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ProgressBar;

public class MainActivity extends AppCompatActivity {

    private Button button;
    private ProgressBar progressBar;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        button = (Button)findViewById(R.id.Button);
        progressBar = (ProgressBar)findViewById(R.id.ProgressBar);
        button.setOnClickListener(new ButtonListener());
    }

    class ButtonListener implements View.OnClickListener{
        @Override
        public void onClick(View view){
            MyThread thread = new MyThread();
            thread.start();
        }
    }

    class MyThread extends Thread{
        @Override
        public void run(){
            for (int i=0;i<=100;i++){
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                progressBar.setProgress(progressBar.getProgress() + 1);
            }
        }
    }
}
