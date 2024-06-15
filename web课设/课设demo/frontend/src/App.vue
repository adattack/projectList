<script setup>
import { useDark, useToggle } from '@vueuse/core'

useDark({
  selector: 'html',
  attribute: 'class',
  valueDark: 'dark',
  valueLight: 'light'
})

useDark({
  onChanged(dark) { useToggle(dark) }
})
</script>
<script>
export default {
  created(){
    //在页面加载时读取sessionStorage里的状态信息
    if (sessionStorage.getItem("store") ) {
    //this.$store.replaceState是vue官方提供的一个api表示替换 store 的根状态
    //里面的Object.assign()表示将store中的状态和sessionStorage中的状态进行合并
      this.$store.replaceState(Object.assign({}, this.$store.state,JSON.parse(sessionStorage.getItem("store"))))
    }

    //在页面刷新时将vuex里的信息保存到sessionStorage里
    //beforeunload表示当浏览器窗口关闭或者刷新时，会触发beforeunload事件
    window.addEventListener("beforeunload",()=>{
      sessionStorage.setItem("store",JSON.stringify(this.$store.state))
    })
  }
}
</script>
<template>
  <!-- <header>
    <div class="wrapper">
      <router-view/>
    </div>
  </header> -->
  <router-view/>
</template>

<style scoped>
header {
  line-height: 1.5;
}
</style>
