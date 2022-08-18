#include "contact.h"
void InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	memset(pc->date, 0, sizeof(pc->date));//�����ڴ�
}
void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->count == MAX)//����
	{
		printf("ͨѶ¼�������޷����\n");
		return;
	}
	printf("���������֣�>");
	scanf("%s", pc->date[pc->count].name);
	printf("���������䣺>");
	scanf("%d", &(pc->date[pc->count].age));
	printf("�������Ա�>");
	scanf("%s", pc->date[pc->count].sex);
	printf("������绰��>");
	scanf("%s", pc->date[pc->count].tele);
	printf("�������ַ��>");
	scanf("%s", pc->date[pc->count].addr);
	pc->count++;
	printf("���ӳɹ�\n");
}
void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%12s\t%30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < pc->count; i++)
	{
		printf("%20s\t%3d\t%5s\t%12s\t%30s\n", pc->date[i].name,
			     
			pc->date[i].age,
			                                   pc->date[i].sex,
                                   pc->date[i].tele,
			                                    pc->date[i].addr);
	}
}
static int FindByName(Contact* pc, char name[])
{
	assert(pc);
	int i = 0;
	for(i=0;i<pc->count;i++)
		if (0 == strcmp(pc->date[i].name, name))
		{
			return i;
        }
	return -1;
}
void DelContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
		assert(pc);//�ж���Ϊ�ղ�ɾ��
		int i = 0;
		if (pc->count == 0)
		{
			printf("ͨѶ¼Ϊ�գ�û����Ϣ����ɾ��\n");
			return;
		}
	printf("������Ҫɾ���˵����֣�>");
	scanf("%s", name);
	//ɾ��
	//1.����
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	//2.ɾ��//��ֹԽ��
	for (i = pos; i < pc->count - 1; i++)
	{
		pc->date[i] = pc->date[i + 1];
	}
	pc->count--;
	printf("ɾ���ɹ�\n");
}
void SearchContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�����˵����֣�>");
	scanf("%s ", &name);
	//1.����
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	//2.��ӡ
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", pc->date[pos].name,
			pc->date[pos].age,
			pc->date[pos].sex,
			pc->date[pos].tele,
			pc->date[pos].addr);
}
//�޸�
void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸��˵����֣�>");
	scanf("%s", &name);
	//1.����
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	printf("Ҫ�޸ĵ�����Ϣ�Ѿ����ҵ�����������ʼ�޸�\n");
	//2.�޸�
	printf("���������֣�>");
	scanf("%s", pc->date[pos].name);
	printf("����������:>");
	scanf("%s", &(pc->date[pos].age));
	printf("�������Ա�:>");
	scanf("%s", pc->date[pos].sex);
	printf("������绰:>");
	scanf("%s", pc->date[pos].sex);
	printf("�������ַ:>");
	scanf("%s", pc->date[pos].addr);
	printf("�޸ĳɹ�\n");
}
int cmp_peo_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
//��������������
void SortContact(Contact* pc)
{
	assert(pc);
	qsort(pc->date, pc->count, sizeof(PeoInfo), cmp_peo_by_name);
	printf("����ɹ�\n");
}
