import { createApp } from 'vue'
import App from './App.vue'
import router from './router'
import store from './store'
import ElementPlus from 'element-plus'
import 'element-plus/dist/index.css'



createApp(App).use(ElementPlus).use(store).use(router).mount('#app')
// axios.defaults.baseURL = "/api"
// axios.defaults.withCredentials = true
// Vue.use(VueAxios,axios);

// Vue.use(mavonEditor)

// router.beforeEach((to,from,next) =>{
//   if(to.meta.requireAuth){
//     // alert(store.state.currentUser)
//     if(store.state.currentUser !== null && store.state.currentUser){
//       next()
//     }
//     else{
//       next({
//         path:'/login',
//         query: {redirect: to.fullPath}
//       })
//     }
//   }
//   else{
//     next()
//   }
// })

// /* eslint-disable no-new */
// new Vue({
//   el: '#app',
//   router,
//   store,
//   components: { App },
//   template: '<App/>'
// })
