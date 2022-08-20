#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define DEFAULT_SZ 3//Ĭ�ϴ��3�˵���Ϣ
#define INC_SZ 2//�ռ䲻�� ����2�˿ռ�
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX  10
#define MAX_TELE 12
#define MAX_ADDR 30
//���͵�����
//�˵���Ϣ
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

//��̬�ڴ�ʵ��ͨѶ¼
typedef struct Contact
{
	PeoInfo* date;//����˵���Ϣ
	int count;//��¼��ǰͨѶ¼��ʵ�ʵ�����
	int capacity;//��ǰͨѶ¼������
}Contact;
//��ʼ��ͨѶ¼
int InitContact(Contact* pc);

//����ͨѶ¼
void DestroyContact(Contact* pc);
//����ͨѶ¼
void AddContact(Contact* pc);
//��ʾͨѶ¼
void ShowContact(const Contact* pc);
//ɾ��ͨѶ¼
void DelContact(Contact* pc);
//����ͨѶ¼
void SearchContact(Contact* pc);
//�޸�ָ����ϵ��
void ModifyContact(Contact* pc);
//����ͨѶ¼�е�����
void SortContact(Contact* pc);
