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
import android.widget.TextView;

import java.util.List;

import cn.jpush.im.android.api.ContactManager;
import cn.jpush.im.android.api.JMessageClient;
import cn.jpush.im.android.api.callback.GetUserInfoListCallback;
import cn.jpush.im.android.api.model.Conversation;
import cn.jpush.im.android.api.model.UserInfo;

/**
 * Created by fenlan on 16-9-19.
 */
public class FriendListAdapter extends BaseAdapter {

    public final static String USERNAME = "com.example.username";
    public final static String MYNAME = "com.example.myname";
    private List<UserInfo> friends;
    private LayoutInflater myInflater;
    private Context mContext;

    public FriendListAdapter(Context context, List<UserInfo> friends) {

        this.friends = friends;
        this.mContext = context;
        myInflater = LayoutInflater.from(context);
    }

    //返回数据集长度
    @Override
    public int getCount() {
        return friends.size();
    }

    @Override
    public Object getItem(int position) {
        return friends.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(final int position, View view, ViewGroup viewGroup) {

        final ViewHolder holder;

        if(view == null) {
            view = myInflater.inflate(R.layout.friend_list_ui, viewGroup, false);
            holder = new ViewHolder();
            holder.friend_username = (TextView)view.findViewById(R.id.friend_username);
            holder.friend_head = (ImageView)view.findViewById(R.id.friend_head_img);
            //holder.tipButton = (TipButton)view.findViewById(R.id.tip_button);
            view.setTag(holder);
        }
        else {
            holder = (ViewHolder)view.getTag();
        }

        holder.friend_username.setText(friends.get(position).getUserName());
        holder.friend_username.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                addAnimation(v);         //点击效果
                String userName = friends.get(position).getUserName();
                String myName = JMessageClient.getMyInfo().getUserName();
                Intent intent = new Intent();
                //holder.tipButton.setVisibility(View.GONE);
                if (userName.equals(JMessageClient.getMyInfo().getUserName())) {
            /*intent.setClass(mContext, MeInfoActivity.class);
            mContext.startActivity(intent);*/
                } else {
                    intent.putExtra(USERNAME, userName);
                    intent.putExtra(MYNAME, myName);
                    intent.setClass(mContext, Jchat_layout.class);
                    mContext.startActivity(intent);
                }
            }
        });
        holder.friend_head.setImageResource(R.mipmap.friend_head);
        return view;
    }

    //暂时不取用该方法
    //@Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id){
        UserInfo userInfo = friends.get(position);
        String userName = userInfo.getUserName();
        Intent intent = new Intent();
        if (userName.equals(JMessageClient.getMyInfo().getUserName())) {
        } else {
            intent.setClass(mContext, Jchat_layout.class);
            mContext.startActivity(intent);
        }
    }

    /**
     * 给CheckBox加点击动画，利用开源库nineoldandroids设置动画
     */
    private void addAnimation(View view) {
        float[] vaules = new float[]{0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1.0f, 1.1f, 1.2f, 1.3f, 1.25f, 1.2f, 1.15f, 1.1f, 1.0f};
        AnimatorSet set = new AnimatorSet();
        set.playTogether(ObjectAnimator.ofFloat(view, "scaleX", vaules),
                ObjectAnimator.ofFloat(view, "scaleY", vaules));
        set.setDuration(1500);
        set.start();
    }

    private class ViewHolder {
        TextView friend_username;
        ImageView friend_head;
        //TipButton tipButton;
    }
}

