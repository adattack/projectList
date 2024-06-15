import { createRouter, createWebHistory } from 'vue-router'
import { unauthorized } from "@/net";
const router = createRouter({
    history: createWebHistory(import.meta.env.BASE_URL),
    routes: [
        {
            path: '/',
            name: 'welcome',
            component: () => import('@/views/WelcomeView.vue'),
            children: [
                {
                    path: '',
                    name: 'welcome-login',
                    component: () => import('@/views/welcome/LoginPage.vue')
                }, {
                    path: 'register',
                    name: 'welcome-register',
                    component: () => import('@/views/welcome/RegisterPage.vue')
                }, {
                    path: 'forget',
                    name: 'welcome-forget',
                    component: () => import('@/views/welcome/ForgetPage.vue')
                }
            ]
        },
        {
            path: '/main',
            name: 'main',
            component: () => import("@/views/Main.vue")
        }, 
        {
            path: '/index',
            name: 'index',
            component: () => import('@/views/IndexView.vue'),
            redirect: '/multchatbox',
            children:[
                {
                    path: '/multchatbox',
                    name:'multchatbox',
                    component: () => import('../components/MultChatBox.vue')
                },
                {
                    path: '/chatwindow',
                    name: 'chatwindow',
                    component: () => import('../views/ChatWindow.vue')   
                 },
                {
                    path:'/groupinfo',
                    name:'groupinfo',
                    component: () => import('../views/GroupInfo.vue'),
                    children: [

                       ]
                    },
                {
                    path:'/friendcircle',
                    name:'friendcircle',
                    component: () => import('../views/FriendCircle.vue')
                },
                {
                    path:'/userinfo',
                    name:'userinfo',
                    component: () => import('../views/UserInfo.vue')
                },
                {
                    path:'/addfriends',
                    name:'addfriends',
                    component: () => import('../components/User/AddFriends.vue')
                }

            ]
        }
    ]
})

router.beforeEach((to, from, next) => {
    const isUnauthorized = unauthorized()
    if(to.name.startsWith('welcome') && !isUnauthorized) {
        next('/index')
    } else if(to.fullPath.startsWith('/index') && isUnauthorized) {
        next('/')
    } else {
        next()
    }
})

export default router
