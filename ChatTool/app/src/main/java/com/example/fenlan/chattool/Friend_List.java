package com.example.fenlan.chattool;

import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Looper;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.KeyEvent;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import com.readystatesoftware.viewbadger.BadgeView;

import java.io.File;
import java.lang.reflect.Array;
import java.util.AbstractList;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import cn.jpush.android.api.JPushInterface;
import cn.jpush.im.android.api.ContactManager;
import cn.jpush.im.android.api.JMessageClient;
import cn.jpush.im.android.api.callback.DownloadAvatarCallback;
import cn.jpush.im.android.api.callback.GetAvatarBitmapCallback;
import cn.jpush.im.android.api.callback.GetUserInfoListCallback;
import cn.jpush.im.android.api.enums.ConversationType;
import cn.jpush.im.android.api.event.BaseNotificationEvent;
import cn.jpush.im.android.api.event.ContactNotifyEvent;
import cn.jpush.im.android.api.event.NotificationClickEvent;
import cn.jpush.im.android.api.model.Conversation;
import cn.jpush.im.android.api.model.Message;
import cn.jpush.im.android.api.model.UserInfo;
import cn.jpush.im.api.BasicCallback;

public class Friend_List extends AppCompatActivity {

    private static ListView Friend_List;
    private static List<UserInfo> friendlist;
    private static FriendListAdapter friendListAdapter;
    private static TextView add_new_friend;
    private static ContactNotifyEvent event;
    private static NotificationClickEvent notificationClickEvent;
    private static TextView refresh_text;
    private static TextView yourName;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_friend__list);
        JMessageClient.registerEventReceiver(this);

        yourName = (TextView)findViewById(R.id.your_name);
        yourName.setText(JMessageClient.getMyInfo().getUserName());
        yourName.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                exitActivity();
            }
        });
        Friend_List = (ListView) findViewById(R.id.Your_Friends_ListView);
        add_new_friend = (TextView) findViewById(R.id.Add_Your_Friend);
        refresh_text = (TextView) findViewById(R.id.refresh_text);

        Thread thread = new Friend_listThread();
        thread.start();

        //接下来为添加好友的Button设置监听器，主要内容为调用库函数中添加好友方法来添加好友
        //今天很给力，终于把我觉得目前最难的问题给解决了，不过还是有点运气因素，在寻找自定义Adapter时候发现了UserInfo
        //的使用方法，所以接下来好多问题就很好解决了
        add_new_friend.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent();
                intent.setClass(Friend_List.this, Add_new_friend.class);

                onPause();

                startActivity(intent);
            }
        });

    }

    private void getFriendList(){
        ContactManager.getFriendList(new GetUserInfoListCallback() {
            @Override
            public void gotResult(int i, String s, List<UserInfo> list) {
                friendlist = list;
            }
        });
    }

    class Friend_listThread extends Thread {
        public void run(){
            //Looper.prepare();
            if (event != null)
                onEventMainThread(event);
            if (notificationClickEvent != null)
                onEvent(notificationClickEvent);

            refresh_text.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    getFriendList();
                    if (friendlist != null) {
                        friendListAdapter = new FriendListAdapter(Friend_List.this, friendlist);
                        Friend_List.setAdapter(friendListAdapter);
                    } else {
                        Toast.makeText(Friend_List.this, "好友列表为空", Toast.LENGTH_SHORT).show();
                    }
                }
            });
            //Looper.loop();
        }
    }

    //此方法没有实现功能，需要修改
    public void onEventMainThread(ContactNotifyEvent event) {
        final String reason = event.getReason();
        final String fromUsername = event.getFromUsername();
        final String appkey = event.getfromUserAppKey();

        switch (event.getType()) {
            case invite_received://收到好友邀请
                new AlertDialog.Builder(this).setTitle(fromUsername+"请求添加好友")
                        .setIcon(android.R.drawable.sym_action_email)
                        .setPositiveButton("同意", new DialogInterface.OnClickListener() {

                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                // 点击“确认”后的操作
                                ContactManager.acceptInvitation(fromUsername, appkey, new BasicCallback() {
                                    @Override
                                    public void gotResult(int i, String s) {
                                        if (i == 0)
                                            Toast.makeText(Friend_List.this,"答应好友请求!",Toast.LENGTH_SHORT).show();
                                        else
                                            Toast.makeText(Friend_List.this,s,Toast.LENGTH_SHORT).show();
                                    }
                                });

                            }
                        })
                        .setNegativeButton("拒绝", new DialogInterface.OnClickListener() {

                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                // 点击“返回”后的操作,这里不设置没有任何操作
                                ContactManager.declineInvitation(fromUsername, appkey, "不认识", new BasicCallback() {
                                    @Override
                                    public void gotResult(int i, String s) {

                                    }
                                });
                            }
                        }).show();

                break;
            case invite_accepted://对方接收了你的好友邀请
                Toast.makeText(Friend_List.this,"对方接受了你的好友邀请",Toast.LENGTH_SHORT).show();
                break;
            case invite_declined://对方拒绝了你的好友邀请
                Toast.makeText(Friend_List.this,"对方拒绝了你的好友邀请",Toast.LENGTH_SHORT).show();
                Toast.makeText(Friend_List.this, reason,Toast.LENGTH_SHORT).show();
                break;
            case contact_deleted://对方将你从好友中删除
                //...
                break;
            default:
                break;
        }
    }

    public void onEvent(NotificationClickEvent notificationClickEvent){
        if (notificationClickEvent == null)
            return;

        Message message = notificationClickEvent.getMessage();
        if (message != null){
            String friendname = message.getFromUser().getUserName();
            ConversationType conversationType = message.getTargetType();
            Conversation conversation = JMessageClient.getSingleConversation(friendname);
            Intent notificationIntent = new Intent(Friend_List.this, Jchat_layout.class);
            if (conversationType == ConversationType.single) {
                conversation = JMessageClient.getSingleConversation(friendname);
                notificationIntent.putExtra(FriendListAdapter.USERNAME, friendname);
            }          //当消息为群聊消息时添加else
            /*int i = 0;
            for (i = 0;i < friendListAdapter.getCount();i++)
            {
                if (friendname == friendlist.get(i).getUserName())
                    break;
            }*/
            conversation.resetUnreadCount();
            notificationIntent.putExtra("fromGroup", false);
            notificationIntent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK
                    | Intent.FLAG_ACTIVITY_CLEAR_TOP);
            Friend_List.this.startActivity(notificationIntent);
        }
    }

    public void exitActivity(){
        new AlertDialog.Builder(this).setTitle("确认退出吗？")
                .setIcon(android.R.drawable.ic_dialog_info)
                .setPositiveButton("确定", new DialogInterface.OnClickListener() {

                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        // 点击“确认”后的操作
                        JMessageClient.logout();
                        Friend_List.this.finish();

                    }
                })
                .setNegativeButton("返回", new DialogInterface.OnClickListener() {

                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        // 点击“返回”后的操作,这里不设置没有任何操作
                    }
                }).show();
    }

    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {

        if (keyCode == KeyEvent.KEYCODE_BACK) {
            Intent home = new Intent(Intent.ACTION_MAIN);
            home.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
            home.addCategory(Intent.CATEGORY_HOME);
            startActivity(home);
            return true;
        }
        return super.onKeyDown(keyCode, event);
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
