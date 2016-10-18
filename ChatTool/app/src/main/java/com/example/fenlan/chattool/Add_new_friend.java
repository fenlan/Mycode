package com.example.fenlan.chattool;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import cn.jpush.im.android.api.ContactManager;
import cn.jpush.im.api.BasicCallback;

public class Add_new_friend extends AppCompatActivity {

    private static EditText input_friend_user_name;
    private static Button add_friend_Button;
    private static EditText input_friend_reason;
    private static Button backButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_new_friend);

        input_friend_reason = (EditText)findViewById(R.id.add_friend_reason);
        input_friend_user_name = (EditText)findViewById(R.id.add_friend_name);
        add_friend_Button = (Button)findViewById(R.id.add_friend_button);
        backButton = (Button)findViewById(R.id.button_back);          //该返回键需要改善或者有问题

        backButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                onBackPressed();
            }
        });

        add_friend_Button.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                String username = input_friend_user_name.getText().toString();
                String add_friend_reason = input_friend_reason.getText().toString();

                //JMessage sdk本身是无好友模式的，也就是说JMessage中任意两个用户不需要建立好友关系 也可以聊天。
                //JMessage仅仅提供好友关系和备注名的托管，任何基于好友关系之上的业务扩展，
                //比如“仅仅好友之间才允许的聊天”等逻辑 需要开发者的应用层自己去做。
                ContactManager.sendInvitationRequest(username, "1bc4ebefae178e1c3acdf86d", add_friend_reason, new BasicCallback() {

                    @Override
                    public void gotResult(int i, String s) {

                        if (i != 0)       Toast.makeText(Add_new_friend.this, s, Toast.LENGTH_LONG).show();
                        else Toast.makeText(Add_new_friend.this, "等待好友响应", Toast.LENGTH_SHORT).show();
                    }
                });
            }
        });
    }

    public void onBackPressed() {
        // TODO Auto-generated method stub
        super.onBackPressed();
    }
}
