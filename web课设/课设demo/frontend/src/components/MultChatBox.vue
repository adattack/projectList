<template>
    <div class="chat-box">
        <div class="chat">
            <div class="list-pane">
                <div class="user-pane">
                    <div class="user-count">
                        <h2>当前在线人数：{{ currentNum }}</h2>
                    </div>
                    <div class="user-list">
                        <div class="user" v-for="user in userList" :key="user">
                            <el-image class="user-img" :src="'@/assets/images/user.png'"></el-image>
                            <p class="username">{{ user }}</p>
                        </div>
                    </div>
                </div>
            </div>
            <div class="chat-pane">
                <div class="chat-header">
                    <h2>MultChatBox</h2>
                </div>
                <div class="chat-message" ref="chatHistory">
                    <div class="user-message" v-for="message in messages" :key="message">
                        <div class="img">
                            <el-image class="user-img" :src="'@/assets/images/user.png'"></el-image>
                        </div>
                        <div class="message">
                            <div class="username">
                                {{ message.name }} <span class="time">{{ message.time }}</span>
                            </div>
                            <div class="text user-text" v-if="name === message.name">
                                {{ message.msg }}
                            </div>
                            <div class="text" v-if="name !== message.name">
                                {{ message.msg }}
                            </div>
                        </div>
                    </div>
                </div>
                <div>
                    <div class="flex flex-wrap items-center">
                        <el-dropdown>
                            <el-button type="primary">
                                表情
                            </el-button>
                            <template #dropdown>
                                <el-dropdown-menu>
                                    <EmojiPicker :native="true" @select="onEmojiSelect" />
                                </el-dropdown-menu>
                            </template>
                        </el-dropdown>
                        <!-- <EmojiPicker :native="true" @select="onEmojiSelect" /> -->
                    </div>
                </div>
                <div class="chat-textarea">
                    <el-input v-model="text" class="user-textarea" type="textarea" resize="none"
                        @keydown.enter="sendButton" id="text"></el-input>
                    <el-button type="primary" class="send-button" @click="sendButton">发送</el-button>
                </div>
            </div>
        </div>
    </div>
</template>

<script lang="ts" setup>
import { ref, onActivated } from "vue";
import router from "@/router";
import useWindowStore from "../store/window";

//当前在线人数
// const userInfoStore = useUserInfoStore()

const currentNum = useWindowStore().getCurNum;
let socket: WebSocket;
let name = sessionStorage.getItem("username");
console.log("当前用户：" + name);
onActivated(() => {

    // 查询浏览器是否支持 WebSocket
    if (typeof WebSocket == "undefined") {
        alert("您的浏览器不支持 WebSocket");
        router.push("/");
        return;
    }

    // 开启 WebSocket 服务
    let socketHost = "localhost";
    let socketPort = "8080";
    let socketUrl =
        "ws://" + socketHost + ":" + socketPort + "/socket/" + name;
    // let socketUrl = "ws://localhost:8080/socket/main-chatroom";
    socket = new WebSocket(socketUrl);

    // 连接服务器
    socket.onopen = () => {
        console.log("已连接至服务器");
    };

    // 浏览器接收服务端发送的消息
    socket.onmessage = (msg) => {
        let data = JSON.parse(msg.data);
        if (data.userlist) {
            // 接收用户列表消息
            userList.value = data.userlist;
            userCount.value = data.userlist.length;
        } else {
            // 接收消息
            messages.value.push(data);

            // 获取节点
            let chatHistory = document.getElementsByClassName("chat-message")[0];
            if (chatHistory.scrollHeight >= chatHistory.clientHeight) {
                setTimeout(function () {
                    //设置滚动条到最底部
                    chatHistory.scrollTop = chatHistory.scrollHeight;
                }, 0);
            }
        }
    };
    // 关闭服务
    socket.onclose = () => {
        console.log("WebSocket 服务已关闭");
    };
    // 错误事件
    socket.onerror = () => {
        console.log("WebSocket 服务发生错误");
    };
});

// 日期转换
const formatTime = (date: Date) => {
    const year = date.getFullYear();
    const month = date.getMonth() + 1;
    const day = date.getDate();
    const hour = date.getHours();
    const minute = date.getMinutes();
    const second = date.getSeconds();

    return (
        [year, month, day].map(formatNumber).join("-") +
        " " +
        [hour, minute, second].map(formatNumber).join(":")
    );
};
const formatNumber = (n: number) => {
    const s = n.toString();
    return s[1] ? s : "0" + s;
};

// 用户数量
let userCount = ref(0);

// 用户列表
let userList = ref([]);

// 信息框
let text = ref("");

// 信息列表
let messages = ref([]);

// 信息
let message = {
    name: "",
    time: "",
    msg: "",
};
// 表情选择
let selectedEmoji = ref('');

// 发送信息
const sendButton = (event: { preventDefault: () => void }) => {
    event.preventDefault();

    if (text.value != null && text.value !== "" && name != null) {
        message.name = name;
        message.time = formatTime(new Date());
        message.msg = text.value;
        socket.send(JSON.stringify(message));
        message.msg = "";
        text.value = "";
    }
};
// 表情选择   
function onEmojiSelect(emoji) {
    // 当用户选择emoji时，将其插入到textarea中
    const textref = document.getElementById("text")
    console.log(emoji);
    if (text) {
        textref.focus();
        const start = text.value.selectionStart;
        const end = text.value.selectionEnd;
        const input = text.value;
        console.log(start, end, input);
        text.value = `${input.slice(0, start)}${emoji.i}${input.slice(end)}`;
    }
    selectedEmoji.value = '';
}

</script>

<style lang="scss">
@import "../assets/css/chat";

.chat-box {
    height: 610px;
}
</style>