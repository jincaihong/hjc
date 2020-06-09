#include "../ThreadPool/BaseThread.h"

CBaseThread::CBaseThread()
:m_bRun(false),m_tid(0)
{

}

CBaseThread::~CBaseThread()
{

}

void CBaseThread::start()
{
	if (m_bRun == false)
	{
		if( pthread_create(&m_tid,NULL,rontine,(void *)this) != 0)
		{
			perror("create thread error : ");
		}

	}
}

bool CBaseThread::isRunning() const
{
	return m_bRun;
}

pthread_t CBaseThread::threadId() const
{
	return m_tid;
}

void * CBaseThread::rontine(void *arg)
{
	//////////////////////////////////////////////////////////////////////////
	//posix�߳�ִ��������״̬joinable״̬��unjoinable״̬��
	//��joinable״̬�����̺߳����Լ����ػ�pthread_exitʱ
	//�����ͷ��߳���ռ�ö�ջ���߳����������ܼ�8K�ࣩ��
	//ֻ�е��������pthread_join֮����Щ��Դ�Żᱻ�ͷš�
	//����unjoinable״̬���̣߳���Щ��Դ���̺߳����˳�ʱ��pthread_exitʱ�Զ��ᱻ�ͷš�
	//unjoinable���Կ�����pthread_createʱָ���������̴߳��������߳���pthread_detach�Լ�, 
	//�磺pthread_detach(pthread_self())����״̬��Ϊunjoinable״̬��ȷ����Դ���ͷš�
	//���߽��߳���Ϊ joinable,Ȼ����ʱ����pthread_join.
	//��ʵ�򵥵�˵�������̺߳���ͷ���� pthread_detach(pthread_self())�Ļ���
	//�߳�״̬�ı�Ϊunjoinable����pthread_exit�߳̾ͻ����˳�ʱ�Զ��ͷ���Դ��

	pthread_detach(pthread_self());//����߳��˳�ʱ�Զ��ͷ���Դ��unjoinable
	CBaseThread *thr = (CBaseThread *)arg;
	thr->m_bRun = true;
	int ret = thr->run();
	thr->m_bRun = false;
	pthread_exit((void *)ret);
}

