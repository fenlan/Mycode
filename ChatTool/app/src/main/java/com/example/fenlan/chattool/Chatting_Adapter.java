package com.example.fenlan.chattool;

import android.animation.AnimatorSet;
import android.animation.ObjectAnimator;
import android.content.Context;
import android.content.Intent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.TextView;

import java.util.Collections;
import java.util.List;

import cn.jmessage.android.uikit.chatting.utils.TimeFormat;
import cn.jpush.im.android.api.JMessageClient;
import cn.jpush.im.android.api.content.TextContent;
import cn.jpush.im.android.api.model.Conversation;
import cn.jpush.im.android.api.model.Message;
import cn.jpush.im.android.api.model.UserInfo;

/**
 * Created by fenlan on 16-10-2.
 */
public class Chatting_Adapter extends BaseAdapter {
    private static final int PAGE_MESSAGE_COUNT = 30;
    public  static String USERNAME = "com.example.username";
    public  static String MYNAME = "com.example.myname";
    private List<cn.jpush.im.android.api.model.Message> chatting_list;
    private LayoutInflater myInflater;
    private Context mContext;
    private int mStart;
    private int mOffset = PAGE_MESSAGE_COUNT;
    private Conversation mConversation;

    public Chatting_Adapter(Context context, String UserName, List<Message> chatting_list) {
        this.USERNAME = UserName;
        this.mContext = context;
        this.mStart = mOffset;
        this.chatting_list = chatting_list;
        myInflater = LayoutInflater.from(context);
    }

    //返回数据集长度
    @Override
    public int getCount() {
        return chatting_list.size();
    }

    @Override
    public Object getItem(int position) {
        return chatting_list.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    public void setData(List<Message> chatting_list)
    {
        // TODO Auto-generated method stub
        this.chatting_list = chatting_list;
    }

    @Override
    public View getView(final int position, View view, ViewGroup viewGroup) {
        Message message = chatting_list.get(position);
        ViewHolder holder;

        if(view == null) {
            view = myInflater.inflate(R.layout.chat_text_ui, viewGroup, false);
            holder = new ViewHolder();
            holder.left_layout = (RelativeLayout)view.findViewById(R.id.left_layout);
            holder.friend_username = (TextView)view.findViewById(R.id.left_tv_name);
            holder.friend_head = (ImageView)view.findViewById(R.id.left_iv_portrait);
            holder.left_chatting_message = (TextView)view.findViewById(R.id.left_tv_content);
            holder.left_chatting_time = (TextView)view.findViewById(R.id.left_tv_time);
            holder.right_layout = (RelativeLayout)view.findViewById(R.id.right_layout);
            holder.myname = (TextView)view.findViewById(R.id.right_tv_name);
            holder.my_head = (ImageView)view.findViewById(R.id.right_iv_portrait);
            holder.right_chatting_message = (TextView)view.findViewById(R.id.right_tv_content);
            holder.right_chatting_time = (TextView)view.findViewById(R.id.right_tv_time);

            view.setTag(holder);
        }
        else {
            holder = (ViewHolder)view.getTag();
        }

        if (message.getFromUser().getUserName() == JMessageClient.getMyInfo().getUserName()) {
            holder.right_layout.setVisibility(View.VISIBLE);
            holder.left_layout.setVisibility(View.GONE);
            holder.myname.setText(message.getFromUser().getUserName());
            //holder.friend_head.setImageResource(R.mipmap.friend_head);
            TimeFormat timeFormat = new TimeFormat(mContext, message.getCreateTime());
            holder.right_chatting_time.setText(timeFormat.getTime());
            TextContent textContent = (TextContent) message.getContent();
            holder.right_chatting_message.setText(textContent.getText());
        }
        else {
            holder.left_layout.setVisibility(View.VISIBLE);
            holder.right_layout.setVisibility(View.GONE);
            holder.friend_username.setText(message.getFromUser().getUserName());
            //holder.friend_head.setImageResource(R.mipmap.friend_head);
            TimeFormat timeFormat = new TimeFormat(mContext,message.getCreateTime());
            holder.left_chatting_time.setText(timeFormat.getTime());
            TextContent textContent = (TextContent) message.getContent();
            holder.left_chatting_message.setText(textContent.getText());
        }
        return view;
    }

    private void incrementStartPosition() {
        ++mStart;
    }

    public void clearMsgList() {
        chatting_list.clear();
        mStart = 0;
        notifyDataSetChanged();
    }

    public Message getLastMsg() {
        if (chatting_list.size() > 0) {
            return chatting_list.get(chatting_list.size() - 1);
        } else {
            return null;
        }
    }

    public void addMsgToList() {
        chatting_list.clear();
        mConversation = JMessageClient.getSingleConversation(USERNAME);
        chatting_list = mConversation.getMessagesFromNewest(0,mOffset);
        Collections.reverse(chatting_list);
        //chatting_list.add(msg);
        //incrementStartPosition();
        notifyDataSetChanged();
    }

    private class ViewHolder {
        RelativeLayout left_layout;
        TextView friend_username;
        TextView left_chatting_message;
        TextView left_chatting_time;
        ImageView friend_head;
        RelativeLayout right_layout;
        TextView myname;
        TextView right_chatting_message;
        TextView right_chatting_time;
        ImageView my_head;
    }
}
