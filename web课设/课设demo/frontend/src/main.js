import { createApp } from 'vue'
import App from './App.vue'
import router from './router'
import axios from "axios";
import pinia from './store'  
import 'element-plus/theme-chalk/dark/css-vars.css'
import Vue3EmojiPicker from 'vue3-emoji-picker';
axios.defaults.baseURL = 'http://localhost:8080'
import 'vue3-emoji-picker/css'
import * as ElementPlusIconsVue from '@element-plus/icons-vue'

const app = createApp(App)
for (const [key, component] of Object.entries(ElementPlusIconsVue)) {
    app.component(key, component)
  }
app.use(router)
app.use(pinia)
app.component('EmojiPicker', Vue3EmojiPicker);
// app.use(axios)

app.mount('#app')

