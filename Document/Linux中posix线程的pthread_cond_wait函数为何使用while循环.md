https://blog.csdn.net/sinat_15799399/article/details/42467139


while:

	   while(条件)
	   {
	   	            pthread_cond_wait(&cond, &mutex);
	   }
		i++;

if：
	
	   if(条件)
	   {
	   	  pthread_cond_wait(&cond, &mutex);
	   }
		i++	   
	   


pthread_cond_wait条件不满足的时候，会暂停在此处，如果pthread_cond_notify 或者pthrea_conf_broadcat的时候
会将其唤醒，如果是if 则直接向下执行i++,而不会再次对条件进行检查。

	   

