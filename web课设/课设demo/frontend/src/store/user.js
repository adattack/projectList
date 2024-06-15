 
import { defineStore } from "pinia"
 
const useUserInfoStore = defineStore('userInfo', {
  // defineStore('userInfo',{})  userInfo就是这个仓库的名称name
  state: () => ({
    online: false,
    userName: '',
    userId: '',
  }),
  getters: {

  },
  action:{

  },
  persist: {
      key: 'piniaStore', //存储名称
      storage: sessionStorage, // 存储方式
      paths:null , //指定 state 中哪些数据需要被持久化。
  },
})
 
export default useUserInfoStore