import { defineStore } from "pinia"
const useWindowStore = defineStore("window", {  
    state: () => ({
        curNum: 0,  

    }),
    getters: {
        getCurNum(state) {
            return state.curNum
        }
    },
    actions: {
        addcurNum() {
            this.curNum++
        },
        subcurNum() {
            this.curNum--
        },
        
    },

    persist: true,
})
export default useWindowStore;