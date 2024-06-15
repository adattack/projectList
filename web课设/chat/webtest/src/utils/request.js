import axios from 'axios'
import { error } from 'console'
import querystring from 'querystring'

const request = axios.create({
  baseURL: 'http://localhost:8080/',
  timeout: 5000
})
//发送数据之前
request.interceptors.request.use(
  config => {
  if (config.method === 'post' || config.method === 'put') {
    if (config.data) {
      config.data = querystring.stringify(config.data)
      config.headers['Content-Type'] = 'application/x-www-form-urlencoded'
    }
  }
  return config
  },
  error =>{
    return Promise.reject(error)
  }
)
//接收数据之后
request.interceptors.response.use(response => {
  if (response.data.code === 200) {
    return response.data.data
  } else {
    return Promise.reject(response.data.message)
  }
}, error => {
  return Promise.reject(error)
})

export default request;
