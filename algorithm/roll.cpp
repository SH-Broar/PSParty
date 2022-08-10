#include <stdio.h>
#include <string.h>

enum pos { top = 1, jg, mid, adc, sup };

typedef struct _champion
{
	char name[30];

	int hp;

	int mp;

	int speed;

	int range;

	enum pos position;

}champion;

void naming(champion* ch)

{

	strcpy(ch[0].name, "����");

	ch[0].hp = 489;

	ch[0].mp = 377;

	ch[0].speed = 335;

	ch[0].range = 550;

	ch[0].position = sup;



	strcpy(ch[1].name, "������");

	ch[1].hp = 561;

	ch[1].mp = 325;

	ch[1].speed = 350;

	ch[1].range = 125;

	ch[1].position = top;



	strcpy(ch[2].name, "����");

	ch[2].hp = 490;

	ch[2].mp = 334;

	ch[2].speed = 330;

	ch[2].range = 550;

	ch[2].position = mid;



	strcpy(ch[3].name, "��������");

	ch[3].hp = 598;

	ch[3].mp = 222;

	ch[3].speed = 355;

	ch[3].range = 125;

	ch[3].position = jg;



	strcpy(ch[4].name, "�ٷ罺");

	ch[4].hp = 537;

	ch[4].mp = 360;

	ch[4].speed = 330;

	ch[4].range = 575;

	ch[4].position = adc;



	strcpy(ch[5].name, "���̰�");

	ch[5].hp = 505;

	ch[5].mp = 392;

	ch[5].speed = 340;

	ch[5].range = 550;

	ch[5].position = mid;



	strcpy(ch[6].name, "����");

	ch[6].hp = 498;

	ch[6].mp = 231;

	ch[6].speed = 330;

	ch[6].range = 550;

	ch[6].position = adc;



	strcpy(ch[7].name, "����ũ��ũ");

	ch[7].hp = 582;

	ch[7].mp = 267;

	ch[7].speed = 325;

	ch[7].range = 125;

	ch[7].position = sup;



	strcpy(ch[8].name, "���־ƴ�");

	ch[8].hp = 560;

	ch[8].mp = 400;

	ch[8].speed = 340;

	ch[8].range = 150;

	ch[8].position = jg;



	strcpy(ch[9].name, "�߽���");

	ch[9].hp = 522;

	ch[9].mp = 0;

	ch[9].speed = 345;

	ch[9].range = 175;

	ch[9].position = mid;



	strcpy(ch[10].name, "������");

	ch[10].hp = 534;

	ch[10].mp = 324;

	ch[10].speed = 325;

	ch[10].range = 550;

	ch[10].position = jg;



	strcpy(ch[11].name, "����");

	ch[11].hp = 565;

	ch[11].mp = 340;

	ch[11].speed = 335;

	ch[11].range = 175;

	ch[11].position = top;



	strcpy(ch[12].name, "�����");

	ch[12].hp = 484;

	ch[12].mp = 360;

	ch[12].speed = 325;

	ch[12].range = 550;

	ch[12].position = adc;



	strcpy(ch[13].name, "�϶����");

	ch[13].hp = 585;

	ch[13].mp = 300;

	ch[13].speed = 340;

	ch[13].range = 125;

	ch[13].position = top;



	strcpy(ch[14].name, "���̿�");

	ch[14].hp = 542;

	ch[14].mp = 275;

	ch[14].speed = 345;

	ch[14].range = 175;

	ch[14].position = top;



	strcpy(ch[15].name, "ī����");

	ch[15].hp = 572;

	ch[15].mp = 300;

	ch[15].speed = 350;

	ch[15].range = 125;

	ch[15].position = jg;



	strcpy(ch[16].name, "����Ʋ��");

	ch[16].hp = 475;

	ch[16].mp = 313;

	ch[16].speed = 325;

	ch[16].range = 650;

	ch[16].position = adc;



	strcpy(ch[17].name, "����");

	ch[17].hp = 560;

	ch[17].mp = 340;

	ch[17].speed = 340;

	ch[17].range = 550;

	ch[17].position = mid;



	strcpy(ch[18].name, "Ÿ��");

	ch[18].hp = 575;

	ch[18].mp = 300;

	ch[18].speed = 340;

	ch[18].range = 150;

	ch[18].position = sup;



	strcpy(ch[19].name, "Ƽ��");

	ch[19].hp = 528;

	ch[19].mp = 240;

	ch[19].speed = 330;

	ch[19].range = 500;

	ch[19].position = sup;

}
//-------------------------------------------------------------------------------------
void Cprintf(champion* ch, int num)
{
	printf("%s  Hp : %d  Mp : %d  Speed : %d  Range : %d", ch[num].name, ch[num].hp, ch[num].mp, ch[num].speed, ch[num].range);
	switch (ch[num].position)
	{
	case top:
		printf(" Top\n");
		break;
	case jg:
		printf(" Jg\n");
		break;
	case mid:
		printf(" Mid\n");
		break;
	case adc:
		printf(" adc\n");
		break;
	case sup:
		printf(" sup\n");
		break;
	}
}

void Search(champion* ch, char* name, int num)
{
	int isSame = -1;
	for (int i = 0; i < num; i++)
	{
		isSame = strcmp(ch[i].name, name);
		if (isSame == 0)
		{
			Cprintf(ch, i);
		}
	}
}

void Insert(champion* ch, char* name, int* data, int* num)
{
	int isSame = -1;
	for (int i = 0; i < *num; i++)
	{
		isSame = strcmp(ch[i].name, name);
		if (isSame == 0)
		{
			printf("���� �̸��� è�Ǿ��� �ֽ��ϴ�!");
			return;
		}
	}

	if (*num >= 25)
	{
		printf("�̹� �ڸ��� ���� á���ϴ�!");
		return;
	}

	strcpy(ch[*num].name, name);
	ch[*num].hp = data[0];
	ch[*num].mp = data[1];
	ch[*num].speed = data[2];
	ch[*num].range = data[3];
	ch[*num].position = (enum pos)data[4];

	*num = *num + 1;
	return;
}

void Delete(champion* ch, char* name, int* num)
{
	int isSame = -1;
	for (int i = 0; i < *num; i++)
	{
		isSame = strcmp(ch[i].name, name);
		if (isSame == 0)
		{
			strcpy(ch[i].name, ch[*num - 1].name);
			ch[i].hp = ch[*num - 1].hp;
			ch[i].mp = ch[*num - 1].mp;
			ch[i].speed = ch[*num - 1].speed;
			ch[i].range = ch[*num - 1].range;
			ch[i].position = ch[*num - 1].position;

			*num = *num - 1;
			return;
		}
	}
	printf("\"�׷� �̸��� ���� è�Ǿ��� ����!\"\n");
}

void DeleteAll(champion* ch, int position, int* num)
{
	for (int i = 0; i < *num; i++)
	{
		if (ch[i].position == (enum pos)position)
		{
			strcpy(ch[i].name, ch[*num - 1].name);
			ch[i].hp = ch[*num - 1].hp;
			ch[i].mp = ch[*num - 1].mp;
			ch[i].speed = ch[*num - 1].speed;
			ch[i].range = ch[*num - 1].range;
			ch[i].position = ch[*num - 1].position;

			*num = *num - 1;
			i--;
		}
	}
}

void printAll(champion* ch, int num)
{
	for (int i = 0; i < num; i++)
	{
		Cprintf(ch, i);
	}
}

void printMAX(champion* ch, int num)
{
	int isMAX = 1;
	for (int i = 0; i < num; i++)
	{
		if (ch[i].hp >= isMAX)
		{
			isMAX = ch[i].hp;
		}
	}
	for (int i = 0; i < num; i++)
	{
		if (ch[i].hp == isMAX)
		{
			Cprintf(ch, i);
		}
	}
}

void reMAX(champion* ch, int num)
{
	int isMAX = 1;
	champion tmpch[25];
	int tmpnum = num;
	int mapping = 0;

	memcpy(tmpch, ch, sizeof(tmpch));

	for (int i = 0; i < tmpnum; i++)
	{
		isMAX = 1;
		for (int j = 0; j < num; j++)
		{
			if (tmpch[j].hp >= isMAX)
			{
				isMAX = tmpch[j].hp;
			}
		}

		for (int j = 0; j < num; j++)
		{
			if (tmpch[j].hp == isMAX)
			{
				strcpy(ch[mapping].name, tmpch[j].name);
				ch[mapping].hp = tmpch[j].hp;
				ch[mapping].mp = tmpch[j].mp;
				ch[mapping].speed = tmpch[j].speed;
				ch[mapping].range = tmpch[j].range;
				ch[mapping].position = tmpch[j].position;

				mapping += 1;

				strcpy(tmpch[j].name, tmpch[num - 1].name);
				tmpch[j].hp = tmpch[num - 1].hp;
				tmpch[j].mp = tmpch[num - 1].mp;
				tmpch[j].speed = tmpch[num - 1].speed;
				tmpch[j].range = tmpch[num - 1].range;
				tmpch[j].position = tmpch[num - 1].position;

				num -= 1;

			}
		}
	}
}

int main()

{
	int numberofchamp = 20;
	int choice;
	bool isError = 0;
	int data[5] = { -9 };
	champion champ[25];
	char nametag[30];
	int postag;

	naming(champ);

	while (1)
	{
		rewind(stdin);
		isError = 0;
		postag = 0;
		strcpy(nametag, " ");
		//���ʱ�ȭ

		printf("1. Search [�̸�] 2. Insert 3. Delete [�̸�] 4. DeleteAll[position] 5. PrintAll 6. FindMaxHp 7. SortByHp\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("ã�� è�Ǿ� �̸��� �Է����ּ��� : ");
			scanf("%s", nametag);


			Search(champ, nametag, numberofchamp);
			break;
		case 2:
			printf("�߰��� è�Ǿ��� �̸��� hp, mp, speed, range, position �� ������� �Է����ּ���\n");
			printf("(position 1 = top, 2 = jg, 3 = mid, 4 = adc, 5 = sup\n");
			scanf("%s %d %d %d %d %d", nametag, &data[0], &data[1], &data[2], &data[3], &data[4]);

			for (int i = 0; i < 5; i++)
			{
				if (data[i] == -9 && isError == 0) // NULL
				{
					printf("�Է��� �߸��Ǿ����ϴ�! \n");
					isError = 1;
				}
			}
			if (data[4] < 1 || data[4] > 5 && isError == 0)
			{
				printf("�Է��� �߸��Ǿ����ϴ�! \n");
				isError = 1;
			}

			if (isError == 0)
			{
				Insert(champ, nametag, data, &numberofchamp);
			}

			break;
		case 3:
			printf("������ è�Ǿ��� �̸��� �Է����ּ���\n");
			scanf("%s", nametag);

			Delete(champ, nametag, &numberofchamp);
			break;
		case 4:
			printf("������ �������� �̸��� �Է����ּ���\n");
			printf("(position 1 = top, 2 = jg, 3 = mid, 4 = adc, 5 = sup\n");
			scanf("%d", &postag);

			if (postag >= 1 && postag <= 5)
			{
				DeleteAll(champ, postag, &numberofchamp);
				continue;
			}
			printf("�Է��� �߸��Ǿ����ϴ�! \n");
			break;
		case 5:
			printAll(champ, numberofchamp);
			break;
		case 6:
			printMAX(champ, numberofchamp);
			break;
		case 7:
			reMAX(champ, numberofchamp);
			break;
		}

		printf("\n");
	}
}
