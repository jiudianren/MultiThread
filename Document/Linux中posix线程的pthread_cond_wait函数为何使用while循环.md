https://blog.csdn.net/sinat_15799399/article/details/42467139


while:

	   while(����)
	   {
	   	            pthread_cond_wait(&cond, &mutex);
	   }
		i++;

if��
	
	   if(����)
	   {
	   	  pthread_cond_wait(&cond, &mutex);
	   }
		i++	   
	   


pthread_cond_wait�����������ʱ�򣬻���ͣ�ڴ˴������pthread_cond_notify ����pthrea_conf_broadcat��ʱ��
�Ὣ�份�ѣ������if ��ֱ������ִ��i++,�������ٴζ��������м�顣

	   

