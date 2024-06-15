package com.example.Socket;

import com.example.config.GetHttpSessionConfigurator;
import com.example.entity.Record;
import com.example.entity.pojo.Message;
import com.example.mapper.RecordMapper;
import com.example.utils.MessageUtils;
import com.example.utils.SpringContextUtil;
import com.fasterxml.jackson.databind.ObjectMapper;
import jakarta.annotation.Resource;
import jakarta.servlet.http.HttpSession;
import jakarta.websocket.*;
import jakarta.websocket.server.ServerEndpoint;
import org.springframework.stereotype.Component;

import java.util.Map;
import java.util.Set;
import java.util.concurrent.ConcurrentHashMap;
@ServerEndpoint(value = "/chat", configurator = GetHttpSessionConfigurator.class)
@Component
public class ChatEndpoint {

    @Resource
    private RecordMapper recordMapper;

    //用来存储每一个客户端对象对应的ChatEndpoint对象
    private static Map<Integer, ChatEndpoint> onlineUsers = new ConcurrentHashMap<>();

    // 用来存储<用户id，用户名>
    private static Map<Integer, String> userInfo = new ConcurrentHashMap<>();

    /**
     * 和某个客户端连接对象，需要通过他来给客户端发送数据
     */
    private Session session;

    /**
     * httpSession中存储着当前登录的用户名
     */
    private HttpSession httpSession;

    /**
     * 连接建立成功调用
     */
    @OnOpen
    public void onOpen(Session session, EndpointConfig config) {
        //需要通知其他的客户端，将所有的用户的用户名发送给客户端
        this.session = session;
        //获取HttpSession对象
        HttpSession httpSession = (HttpSession) config.getUserProperties().get(HttpSession.class.getName());
        //将该httpSession赋值给成员httpSession
        this.httpSession = httpSession;

        //获取用户名
        Integer userId = (Integer) httpSession.getAttribute("userId");
        //存储该链接对象
        onlineUsers.put(userId, this);
        // 获取用户id
        String username = (String) httpSession.getAttribute("username");
        // 存储<用户Id,用户名>
        userInfo.put(userId, username);

        // 获取需要推送的消息
        String message = MessageUtils.getMessage(true, null, userInfo);
        // 广播给所有的用户
        broadcastAllUsers(message);
    }

    private void broadcastAllUsers(String message) {
        try {
            //遍历 onlineUsers 集合
            Set<Integer> nameIds = onlineUsers.keySet();
            for (Integer nameId : nameIds) {
                //获取该用户对应的ChatEndpoint对象
                ChatEndpoint chatEndpoint = onlineUsers.get(nameId);
                //发送消息
                chatEndpoint.session.getBasicRemote().sendText(message);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private Set<Integer> getUserIds() {
        return onlineUsers.keySet();
    }

    /**
     * 接收到消息时调用
     */
    @OnMessage
    public void onMessage(String message, Session session) {
        try {
            //获取客户端发送来的数据  {"toId":2,"message":"你好"}
            ObjectMapper mapper = new ObjectMapper();
            Message mess = mapper.readValue(message, Message.class);

            //获取当前登录的用户id
            Integer userId = (Integer) httpSession.getAttribute("userId");

            //拼接推送的消息
            String data = MessageUtils.getMessage(false, userId, mess.getMessage());

            //将数据推送给指定的客户端
            ChatEndpoint chatEndpoint = onlineUsers.get(mess.getToId());
            // 如果在线,则将消息发送给接收者
            if (chatEndpoint != null) {
                chatEndpoint.session.getBasicRemote().sendText(data);
            }

            // 保存到数据库
            Record record = new Record(null, userId, mess.getToId(), mess.getMessage());
            if (recordMapper == null) {
                this.recordMapper = (RecordMapper) SpringContextUtil.getBean("recordMapper");
            }
            int row;
            row = recordMapper.addRecord(record);
            if (row == 0) {
                // 抛出异常
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * 连接关闭时调用
     */
    @OnClose
    public void onClose(Session session) {
        //获取用户名
        Integer userId = (Integer) httpSession.getAttribute("userId");
        //移除连接对象
        onlineUsers.remove(userId);
        // 移除<用户id,用户名>
        userInfo.remove(userId);
        //获取需要推送的消息
        String message = MessageUtils.getMessage(true, null, userInfo);
        //广播给所有的用户
        broadcastAllUsers(message);
    }
}
