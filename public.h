#ifndef _PUBLIC_H_
#define _PUBLIC_H_

typedef struct PackHead// ��ͷ
{
	int func_num;//���ܺ�
						//������-1001����¼��-1002 ע���-1003 ���������-1004
						//��ƵƵ��Ӧ���-2001����Ƶ����Ӧ���-2002����Ƶ����Ӧ���-2003����Ƶ�б�Ӧ���-2004
						//�ϴ���Ƶ�㲥�����-3001���ϴ���Ƶ�㲥ʱ�������-3002���ϴ�Ӧ���-3001����Ƶ�㲥��-3002����Ƶ�㲥ʱ����
						//������ʷ�����-4001

	int pack_size;//�����ܳ���
	int counts;    //�������ݸ���
	int des_fd;		//Ŀ��ͻ���fd���������õ���
}PackHead_t;

typedef struct PackTail//��β,������֤���ݰ���������
{
	int pack_tail;//����Ϊ55
}PackTail_t;

typedef struct Login// ��¼�����
{
	int user_id;
	char user_name[10];// ��¼�û���
	char passwd[10];//����
}Login_t;

typedef struct LoginRet// ��¼Ӧ���
{
	int user_id;//�û�ID
	int login_ret;	//��¼����� 0-��¼�ɹ���1-��¼ʧ��
}LoginRet_t;

typedef struct Register// ע�������
{
	char user_name[10];// ע���û���
	char passwd[10];//ע������
	char passwd2[10];//��������
}Register_t;

typedef struct RegisterRet// ע��Ӧ���
{
	int user_id;//�û�ID
	int Register_ret;	//ע������ 0-ע��ɹ���1-ע��ʧ��
}RegisterRet_t;

typedef struct Forget// �������������
{
	char user_name[10];// ��¼�û���
	char passwd[10];//������
	char passwd2[10];//��������
}Forget_t;

typedef struct ForgetRet// ��������Ӧ���
{
	int user_id;//�û�ID
	int Register_ret;	//�޸��������� 0-�޸ĳɹ���1-�޸�ʧ��
}ForgetRet_t;

typedef struct VideoChannel//��ƵƵ��Ӧ���
{
	int channel_id; //Ƶ��ID
	char channel_name[10];//Ƶ������
}VideoChannel_t;

typedef struct VideoType//��Ƶ����Ӧ���
{
	int type_id;//����ID
	int channel_id;//Ƶ��ID
	char type_name[10];//��������
}VideoType_t;

typedef struct VideoArea//��Ƶ����Ӧ���
{
	int area_id;//����ID
	int channel_id;//Ƶ��ID
	char area_name[10];//��������
}VideoArea_t;

typedef struct selectVideoList//ѡ��������Ƶ�������
{
	int channel_id;//Ƶ��ID
	int sort_id;//����ID
	int type_id;//����ID
	int area_id;//����ID
	int time_id;//���id
}selectVideoList_t;

typedef struct VideoList//��Ƶ�б�Ӧ���
{
	int video_id;//��ƵID
	int channel_id;//Ƶ��ID
	int type_id;//����ID
	int area_id;//����ID
	char video_name[18];//��Ƶ����
	int play_times;//���Ŵ���
	char play_locad[70];
}VideoList_t;

typedef struct VideoPlay//�ϴ���Ƶ�㲥�����
{
	int user_id;//�û�ID��û�е�¼�Ļ�Ϊ0��
	int video_id;//��ƵID
}VideoPlay_t;

typedef struct VideoRecord//�ϴ���Ƶ�㲥ʱ���������û�е�¼�Ļ�����Ҫ����
{
	int user_id;//�û�ID
	int video_id;//��ƵID
	int video_seek;//����ʱ��
}VideoRecord_t;

typedef struct UpLoad//�ϴ�Ӧ���
{
	int results;//�ϴ������0-�ϴ��ɹ���1-�ϴ�ʧ��
}UpLoad_t;

typedef struct PlayHistorys//������ʷ����4001
{
	int user_id;//�û�ID
}Play_t;
typedef struct PlayHistory//������ʷӦ���
{
	int video_id;//��ƵID
	char video_name[18];//��Ƶ����
	int play_times;//���Ŵ���
	int video_seek;//����ʱ��
}PlayHistory_t;

typedef struct Search// ������Ƶ�����1005
{
	char vedio_name[30];
}Search_t;

typedef struct SearchRet// ������ƵӦ���1005
{
	int Search_ret;	//�޸��������� 0-�����ɹ���1-����ʧ��
}SearchRet_t;
typedef struct ClearHistory//��ղ��ż�¼4002
{
	int user_id;//�û�ID
}ClearHistory_t;
#endif
