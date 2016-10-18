package com.example.fenlan.chattool;

import android.app.Activity;
import android.content.Intent;
import android.os.Looper;
import android.os.Message;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.view.inputmethod.InputMethodManager;
import android.widget.AbsListView;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import cn.jmessage.android.uikit.chatting.ChatActivity;
import cn.jmessage.android.uikit.chatting.ChatView;
import cn.jpush.im.android.api.ContactManager;
import cn.jpush.im.android.api.JMessageClient;
import cn.jpush.im.android.api.callback.GetUserInfoListCallback;
import cn.jpush.im.android.api.content.CustomContent;
import cn.jpush.im.android.api.content.EventNotificationContent;
import cn.jpush.im.android.api.content.ImageContent;
import cn.jpush.im.android.api.content.TextContent;
import cn.jpush.im.android.api.content.VoiceContent;
import cn.jpush.im.android.api.enums.ConversationType;
import cn.jpush.im.android.api.event.MessageBaseEvent;
import cn.jpush.im.android.api.event.MessageEvent;
import cn.jpush.im.android.api.model.Conversation;
import cn.jpush.im.android.api.model.GroupInfo;
import cn.jpush.im.android.api.model.UserInfo;

public class Jchat_layout extends AppCompatActivity {

    public static String UserName;
    public static String Myname;
    public static Chatting_Adapter chatting_adapter;
    public static TextView refreash_chatting;
    public static MessageEvent event;
    public static List<cn.jpush.im.android.api.model.Message> chatting_list;
    private static Button back_button;
    private static Button send_message_button;
    private static ListView chatting_message;
    public static EditText input_message;
    private static TextView chatting_friend_name;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getWindow().setSoftInputMode(WindowManager.LayoutParams.SOFT_INPUT_ADJUST_PAN);
        setContentView(R.layout.activity_jchat_layout);
        JMessageClient.registerEventReceiver(this);

        Intent intent = getIntent();
        UserName = intent.getStringExtra(FriendListAdapter.USERNAME);
        Myname = intent.getStringExtra(FriendListAdapter.MYNAME);
        chatting_friend_name = (TextView)findViewById(R.id.Chatting_friend);
        chatting_friend_name.setText(UserName);
        back_button = (Button)findViewById(R.id.chatting_button_back);
        send_message_button = (Button)findViewById(R.id.send_message);
        chatting_message = (ListView) findViewById(R.id.chatting_message_list_view);
        input_message = (EditText)findViewById(R.id.input_message);
        //refreash_chatting = (TextView)findViewById(R.id.refresh_text1);
        back_button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                onBackPressed();
            }
        });
        send_message_button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String textmessage = input_message.getText().toString();
                if (textmessage.equals(""))
                {
                    Toast.makeText(Jchat_layout.this, "请输入内容",Toast.LENGTH_SHORT).show();
                }
                else {
                    cn.jpush.im.android.api.model.Message message;
                    message = Conversation.createSingleConversation(UserName, "1bc4ebefae178e1c3acdf86d").createSendTextMessage(textmessage);
                    JMessageClient.sendMessage(message);
                    chatting_adapter.addMsgToList();
                    input_message.setText(null);
                }
            }
        });

        getChattingList();
        if (chatting_list != null) {
            chatting_message.setEmptyView(findViewById(R.id.Is_Empty1));
            chatting_adapter = new Chatting_Adapter(Jchat_layout.this, UserName, chatting_list);
            chatting_message.setAdapter(chatting_adapter);
        }
        /*refreash_chatting.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                getChattingList();
                if (chatting_list != null)
                {
                    chatting_adapter = new Chatting_Adapter(Jchat_layout.this, chatting_list);
                    chatting_message.setAdapter(chatting_adapter);
                }
            }
        });*/
        Thread thread = new ChatThread();
        thread.start();
    }

    class ChatThread extends Thread {
        public void run(){
            Looper.prepare();
            if (event != null)
                onEvent(event);
            Looper.loop();

        }
    }

    private void getChattingList(){
        if (Conversation.createSingleConversation(UserName, "1bc4ebefae178e1c3acdf86d").getMessagesFromNewest(0, 20) != null)
        chatting_list = Conversation.createSingleConversation(UserName, "1bc4ebefae178e1c3acdf86d").getMessagesFromNewest(0, 20);
    }

    @Override
    protected void onDestroy() {
        JMessageClient.unRegisterEventReceiver(this);
        super.onDestroy();
    }

    public void onEvent(MessageEvent event){
        final cn.jpush.im.android.api.model.Message msg = event.getMessage();

        switch (msg.getContentType()){
            case text:
                //处理文字消息
                TextContent textContent = (TextContent) msg.getContent();
                textContent.getText();
                //getChattingList();
                //Toast.makeText(Jchat_layout.this, textContent.getText(), Toast.LENGTH_SHORT).show();
                break;
            case image:
                //处理图片消息
                ImageContent imageContent = (ImageContent) msg.getContent();
                imageContent.getLocalPath();//图片本地地址
                imageContent.getLocalThumbnailPath();//图片对应缩略图的本地地址
                break;
            case voice:
                //处理语音消息
                VoiceContent voiceContent = (VoiceContent) msg.getContent();
                voiceContent.getLocalPath();//语音文件本地地址
                voiceContent.getDuration();//语音文件时长
                break;
            case custom:
                //处理自定义消息
                CustomContent customContent = (CustomContent) msg.getContent();
                customContent.getNumberValue("custom_num"); //获取自定义的值
                customContent.getBooleanValue("custom_boolean");
                customContent.getStringValue("custom_string");
                break;
            case eventNotification:
                //处理事件提醒消息
                EventNotificationContent eventNotificationContent = (EventNotificationContent)msg.getContent();
                switch (eventNotificationContent.getEventNotificationType()){
                    case group_member_added:
                        //群成员加群事件
                        break;
                    case group_member_removed:
                        //群成员被踢事件
                        break;
                    case group_member_exit:
                        //群成员退群事件
                        break;
                }
                break;
        }
        runOnUiThread(new Runnable(){
            public void run(){
                UserInfo userInfo = (UserInfo) msg.getTargetInfo();
                String targetId = userInfo.getUserName();
                String appKey = userInfo.getAppKey();
                //判断消息是否在当前会话中
                if (targetId.equals(UserName) && appKey.equals("1bc4ebefae178e1c3acdf86d")) {
                    cn.jpush.im.android.api.model.Message lastMsg = chatting_adapter.getLastMsg();
                    //收到的消息和Adapter中最后一条消息比较，如果最后一条为空或者不相同，则加入到MsgList
                    if (lastMsg == null || msg.getId() != lastMsg.getId()) {
                        chatting_adapter.addMsgToList();
                    } else {
                        chatting_adapter.notifyDataSetChanged();
                    }
                }
            }
        });
    }

    class NotificationClickEvent extends Activity {

        @Override
        protected void onDestroy() {
            JMessageClient.unRegisterEventReceiver(this);
            super.onDestroy();
        }
        public void onEvent(NotificationClickEvent event){
            Intent notificationIntent = new Intent(Jchat_layout.this, Jchat_layout.class);
            Jchat_layout.this.startActivity(notificationIntent);//自定义跳转到指定页面
        }

    }

    public void onBackPressed() {
        // TODO Auto-generated method stub
        super.onBackPressed();
    }
}
