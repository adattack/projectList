<template>
  <div>
    <StatusBar/>
    <RouterView v-slot="{ Component }">
      <KeepAlive>
        <component :is="Component" />
      </KeepAlive>
    </RouterView>
  </div>
</template>
<script setup>
import StatusBar from '../components/User/StatusBar.vue';
</script>
<style scoped>

</style>
