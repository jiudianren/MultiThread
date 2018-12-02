/*
 * condition.h
 *
 *  Created on: 2018��12��2��
 *      Author: Administrator
 */

#ifndef SIMPLETHREADPOOL_CONDITION_H_
#define SIMPLETHREADPOOL_CONDITION_H_


#include <pthread.h>

//��װһ��������������������Ϊ״̬
typedef struct condition
{
    pthread_mutex_t pmutex;
    pthread_cond_t pcond;
}condition_t;

//��״̬�Ĳ�������
int condition_init(condition_t *cond);
int condition_lock(condition_t *cond);
int condition_unlock(condition_t *cond);
int condition_wait(condition_t *cond);
int condition_timedwait(condition_t *cond, const struct timespec *abstime);
int condition_signal(condition_t* cond);
int condition_broadcast(condition_t *cond);
int condition_destroy(condition_t *cond);


#endif /* SIMPLETHREADPOOL_CONDITION_H_ */