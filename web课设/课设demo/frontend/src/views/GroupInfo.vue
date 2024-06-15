<template>
    <div class="background">
        <el-row class="tac">
            <el-col :span="6">
                <div class="title">
                    <br />
                    <el-row>
                        <el-col :span="2"></el-col>
                        <el-col :span="8">我的联系人</el-col>
                        <el-divider />
                    </el-row>
                </div>
                <div class="title">
                    <el-scrollbar height="580px">
                        <div v-for="friend in friends" :key="friend.id" class="friendBar">
                            <el-row class="friend" style="display: flex; align-items: center;">
                                <el-col :span="1"></el-col>
                                <el-col :span="22">
                                    <el-card class="friendCard" @click="handleClick(friend.id)">
                                        <el-row>
                                            <el-col span="4" class="avatar">
                                                <el-avatar shape="square" :size="40" :src="friend.avater"></el-avatar>
                                                <span class="friendName">
                                                     {{ friend.name }}
                                                </span>
                                            </el-col>
                                        </el-row>
                                    </el-card>
                                </el-col>
                                <el-col :span="19">
                                </el-col>
                                <el-col :span="2"></el-col>
                            </el-row>
                        </div>
                        <br>
                    </el-scrollbar>
                </div>
            </el-col>
        </el-row>
    </div>
</template>

<script lang="ts" setup>
import { ref } from 'vue'
import { useRouter } from 'vue-router';
const router = useRouter()
const currentComponent = ref('GroupInfo')
const handleOpen = (key: string, keyPath: string[]) => {
    console.log(key, keyPath)
}
const handleClose = (key: string, keyPath: string[]) => {
    console.log(key, keyPath)
}
//status 0: offline 1: online
const friends = [
    { id: 1, name: '张三', avater: 'https://telegraph-image.pages.dev/file/e5af7e850e7370a663757.png', status: 1 },
    { id: 2, name: '张三1', avater: '', status: 1 },
    { id: 3, name: '张三2', avater: '', status: 1 },
    { id: 4, name: '张三3', avater: '', status: 1 },
    { id: 5, name: '张三4', avater: '', status: 1 },
]
const handleClick = (id: number) => {
    console.log('与'+ id + '的聊天窗口')
    router.push({ name: 'chatwindow', params: { id: id } })
}
</script>
<style>
.background {
    background-color: rgba(165, 175, 175, 0.468);
}

.title {
    background-color: white;
}



.statusdotOn {
    border-radius: 100%;
    color: rgb(0, 0, 0);
    z-index: 10;
    position: absolute;
    left: 10px;
}

.statusdotOff {
    border-radius: 100%;
    color: rgb(13, 255, 0);
}
.friendCard {
    height: 70px;
    border-radius: 20px;
    
}

.friendName{
    font-size: 16px;
    position: absolute;
}
.avatar {
    margin-bottom: 20px;
}
.statusline {   
    height: 30px;
}
</style>