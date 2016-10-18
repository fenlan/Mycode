package com.example.fenlan.chattool;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import cn.jmessage.android.uikit.chatting.utils.SharePreferenceManager;
import cn.jpush.android.api.JPushInterface;
import cn.jpush.im.android.api.JMessageClient;
import cn.jpush.im.api.BasicCallback;

public class MainActivity extends AppCompatActivity {

    private static EditText inputName;
    private static EditText inputPassword;
    private static Button loginButton;
    private static Button NewerRegisterButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        JMessageClient.init(getApplication());
        JPushInterface.setDebugMode(true);

        inputName = (EditText)findViewById(R.id.inputName);
        inputPassword = (EditText)findViewById(R.id.inputPassword);
        loginButton = (Button)findViewById(R.id.loginButton);
        NewerRegisterButton = (Button)findViewById(R.id.NewerRegisterButton);

        /*NewerRegisterButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String inputName1 = inputName.getText().toString();
                String inputPassword1 = inputPassword.getText().toString();

                register(inputName1, inputPassword1);
            }
        });*/

        loginButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String inputName1 = inputName.getText().toString();
                String inputPassword1 = inputPassword.getText().toString();

                login(inputName1, inputPassword1);

            }
        });
    }

    public void register(String name, String password) {
        JMessageClient.register(name, password, new BasicCallback() {

            @Override
            public void gotResult(int arg0, String arg1) {
                if (arg0==0) {
                    Toast.makeText(MainActivity.this,"注册成功",Toast.LENGTH_SHORT).show();
                }
            }
        });
    }

    public void login(String name, String Password) {
        JMessageClient.login(name,Password, new BasicCallback() {

            @Override
            public void gotResult(int arg0, String arg1) {
                if (arg0==0) {
                    Toast.makeText(MainActivity.this, "登录成功", Toast.LENGTH_SHORT).show();
                    Intent intent = new Intent();
                    intent.setClass(MainActivity.this, Friend_List.class);
                    intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
                    startActivity(intent);
                }
                else {
                    Toast.makeText(MainActivity.this, "登录失败", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }

    @Override
    protected void onResume() {
        super.onResume();
        JPushInterface.onResume(this);
    }

    @Override
    protected void onPause() {
        super.onPause();
        JPushInterface.onPause(this);
    }
}
