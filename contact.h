#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <assert.h>
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

//ͨѶ¼
typedef struct Contact
{
	PeoInfo date[MAX];//����˵���Ϣ
	int count;//��¼��ǰͨѶ¼��ʵ�ʵ�����
}Contact;
//��ʼ��ͨѶ¼
void InitContact(Contact* pc);
//����ͨѶ¼
void AddContact(Contact* pc);
//��ʾͨѶ¼
void ShowContact(const Contact* pc);
//ɾ��ͨѶ¼
void DelContact(Contact* pc);
