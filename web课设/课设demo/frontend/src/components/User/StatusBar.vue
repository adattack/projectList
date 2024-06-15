<template>
    <div class="menu-back">
        <el-menu :default-active="activeIndex" class="el-menu-demo" mode="horizontal" :ellipsis="false"
            @select="handleSelect" router>
            <el-menu-item index="/multchatbox">
                <el-image src="src/assets/images/logo.svg" style="width: 120px;"></el-image>
            </el-menu-item>
            <div class="flex-grow" />

            <div> 
                
                <el-input v-model="search" style="width: 200px" placeholder="添加好友"  class="search-input" clearable/>
               
                <el-button type="primary" @click="searchFunction" class="search-btn">
                    <el-icon><Search /></el-icon>搜索</el-button>
            </div>
                
            <el-menu-item index="/multchatbox">主页</el-menu-item>
            <el-menu-item index="2">好友圈</el-menu-item>
            <el-menu-item index="3">我的</el-menu-item>
            <el-menu-item index="/groupinfo">群组</el-menu-item>
            <el-sub-menu index="5">
                <template #title>
                    <div direction="horizontal" style=display:flex;align-items:center;>
                        <el-avatar size="small" shape="square" src=AvatarUrl>
                            <div class="status-dot"></div>
                        </el-avatar>
                    </div>
                </template>
                <el-menu-item index="5-1" style=display:flex;align-items:center;>

                </el-menu-item>
                <el-menu-item index="5-2"></el-menu-item>
                <el-menu-item index="">
                    <div class="logout-btn">
                        <el-button @click="userLogout" class="logout-btn">退出登录</el-button>
                    </div>

                </el-menu-item>
            </el-sub-menu>

        </el-menu>
    </div>
</template>


<script lang="ts" setup>
import { ref } from 'vue'
import useWindowStore from '../../store/window'
const store = useWindowStore();
const activeIndex = ref('1')
const handleSelect = (key: string, keyPath: string[]) => {
    // console.log(key, keyPath)
}
const search = ref('')
import { Search } from '@element-plus/icons-vue'
import { logout } from '@/net'
import router from "@/router";
function userLogout() {
    logout(() => router.push("/"))
    store.subcurNum();
    //   store.commit("setDisconnect")
    sessionStorage.setItem("isConnect", 0)
}
function searchFunction() {
    console.log(search.value)

}
</script>
<style scoped>
.flex-grow {
    flex-grow: 1;
}

.logout-btn {
    width: 100%;
}

.menu-back {
    background-color: cornflowerblue;
}

.status-dot {
    border-radius: 100%;
    height: 12px;
    width: 12px;
    position: relative;
    top: 8px;
    left: 8px;
    background-color: rgb(0, 255, 64);
}
.search-input {
    background-color: white;  
    position: absolute;
    top: 15px;
    right: 480px;
}
.search-btn{
    position: absolute;
    top: 15px;
    right: 400px;
}
</style>