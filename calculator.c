#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(void)
{
	printf("=================================================================================================\n\n");
	printf("---��ȿ���� ����---\n");
	printf("\n");
	printf("***��� ���***\n\n");
	printf("�����ڿ� ����� ���� �Է��ϼ���.(����� ������ �������� �������ּ���.)\n");
	printf("�Է��ϴ� ���ڵ��� ��ȿ ���ڸ� �Ǵ��մϴ�.\n");
	printf("��ȿ ���� ��� ��Ģ�� ���� �Ǵ��� ��ȿ ���ڸ� ������� ���� ��갪�� �����մϴ�.\n");
	printf("���� ��� ���� ��ȿ ������ ������ �������� ��µ˴ϴ�.\n\n");
	printf("=================================================================================================\n\n");
	int choose;
	while (1)
	{
		printf("���� ����� ���Ͻø� 1��, ��Ģ������ ���Ͻø� 2��, �α� ����� ���Ͻø� 3���� �����ּ���. : ");
		scanf("%d", &choose);
		printf("\n");
		if (choose != 1 && choose != 2 && choose != 3)
		{
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.");
			printf("\n\n");
			continue;
		}
		if (choose == 1)
		{
			int keep;
			char num[64];
			char under[64];
			printf("�ذ� ������ �������� �����Ͽ� �Է����ּ���. : ");
			scanf("%s %s", under, num);
			printf("\n\n");
			double a = atof(num);
			double und = atof(under);
			double exp = pow(und, a);
			int i = 0;
			int b = 0;
			int c = 0;
			while (num[i] != '.')
			{
				i++;
				if (num[i] == '\0')
				{
					int j = 0;
					int k = 0;
					int l = 0;
					while (under[j] != '.')
					{
						if (under[j] == '0')
						{
							if (l == 0)
								j++;
							else
							{
								k++;
								j++;
							}
						}
						else
						{
							k++;
							l++;
							j++;
						}
					}
					j++;
					int m = 0;
					int n = 0;
					while (under[j] != '\0')
					{
						if (under[j] == '0')
							if (l == 0 && n == 0)
								j++;
							else
							{
								m++;
								j++;
							}
						else
						{
							j++;
							k++;
							n++;
						}
						if (under[j] == '\0')
							k += m;
					}
					printf("����� : %s ^ %s = %.12f\n\n", under, num, exp);
					printf("��ȿ���� ���� : %d��\n\n", k);
					goto back1;
				}
			}
			i++;
			while (num[i] != '\0')
			{
				if (num[i] == '0')
				{
					if (b == 0)
						i++;
					else
					{
						c++;
						i++;
					}
				}
				else
				{
					b++;
					i++;
				}
				if (num[i] == '\0')
					b += c;
			}
			printf("����� : %s ^ %s = %.12f\n\n", under, num, exp);
			printf("��ȿ���� ���� : %d��\n\n", b);
		back1:
			printf("����Ͻ÷��� 0��, �����Ͻ÷��� �ƹ� ���ڳ� �Է����ּ���. : ");
			scanf("%d", &keep);
			printf("\n\n");
			if (keep == 0)
				continue;
			else
			{
				printf("=================================================================================================\n\n");
				printf("���α׷��� �����մϴ�.\n");
				printf("=================================================================================================\n\n");
				break;
				return 0;
			}
		}
		if (choose == 2)
		{
			int keep = 0;
			char calc = 0;
			char num1[20];
			char num2[20];
			int count1 = 0;
			int count2 = 0;
			int i = 2, j = 0;
			double value = 0.0;
			int k;
			printf("�����ڸ� �Է����ּ���. : ");
			scanf(" %c", &calc);
			printf("\n");
			printf("���� 2���� �������� �����Ͽ� �Է����ּ���. : ");
			scanf("%s %s", num1, num2);
			printf("\n");
			if (atof(num1) >= 1) {
				count1 = strlen(num1) - 1;
			}
			else if (atof(num1) < 1) {
				while (num1[i] != '\0') {
					if (num1[i] == '0')
						i++;
					else {
						count1++;
						i++;
					}
				}
			}
			if (atof(num2) >= 1) {
				count2 = strlen(num2) - 1;
			}
			else if (atof(num1) < 1) {
				while (num1[i] != '\0') {
					if (num1[i] == '0')
						i++;
					else {
						count1++;
						i++;
					}
				}
			}
			switch (calc) {//�ϴ� ���� ��� ���� ��ȿ ���� ���� ������ �� �ְ� ��������ϴ�.
			case '+':
				value = atof(num1) + atof(num2);
				printf("����� : %s %c %s = %.12lf\n\n", num1, calc, num2, value);
				if (count1 > count2) {
					printf("��ȿ���� ���� : %d��\n\n", count2);
				}
				else
					printf("��ȿ���� ���� : %d��\n\n", count1);
				break;
			case '-':
				value = atof(num1) - atof(num2);
				printf("����� : %s %c %s = %.12lf\n\n", num1, calc, num2, value);
				if (count1 > count2) {
					printf("��ȿ���� ���� : %d��\n\n", count2);
				}
				else
					printf("��ȿ���� ���� : %d��\n\n", count1);
				break;
			case '*':
				value = atof(num1) * atof(num2);
				printf("����� : %s %c %s = %.12lf\n\n", num1, calc, num2, value);
				if (count1 > count2) {
					printf("��ȿ���� ���� : %d��\n\n", count2);
				}
				else
					printf("��ȿ���� ���� : %d��\n\n", count1);
				break;
			case '/':
				value = atof(num1) / atof(num2);
				printf("����� : %s %c %s = %.12lf\n\n", num1, calc, num2, value);
				if (count1 > count2) {
					printf("��ȿ���� ���� : %d��\n\n", count2);
				}
				else
					printf("��ȿ���� ���� : %d��\n\n", count1);
				break;
			}
			printf("����Ͻ÷��� 0��, �����Ͻ÷��� �ƹ� ���ڳ� �Է����ּ���. : ");
			scanf("%d", &keep);
			printf("\n\n");
			if (keep == 0)
				continue;
			else
			{
				printf("=================================================================================================\n\n");
				printf("���α׷��� �����մϴ�.\n");
				printf("=================================================================================================\n\n");
				break;
				return 0;
			}
		}
		if (choose == 3)
		{
			int keep;
			char num[64];
			printf("������ �Է����ּ��� : ");
			scanf("%s", num);
			printf("\n\n");
			double a = atof(num);
			double ae = log(a);
			double a10 = log10(a);
			int i = 0;
			int b = 0;
			int c = 0;
			while (num[i] != '.')
			{
				if (num[i] == '0')
				{
					if (c == 0)
						i++;
					else
					{
						b++;
						i++;
					}
				}
				else
				{
					b++;
					c++;
					i++;
				}
				if (num[i] == '\0')
				{
					printf("�ڿ��α� ����� : ln%s = %.12f\n\n", num, ae);
					printf("���α� ����� : log%s = %.12f\n\n", num, a10);
					printf("�Ҽ��� ���� ��ȿ���� ���� : %d��\n\n", b);
					goto back3;
				}
			}
			i++;
			int d = 0;
			int e = 0;
			while (num[i] != '\0')
			{
				if (num[i] == '0')
				{
					if (c == 0 && e == 0)
						i++;
					else
					{
						d++;
						i++;
					}
				}
				else
				{
					e++;
					b++;
					i++;
				}
				if (num[i] == '\0')
					b += d;
			}
			printf("�ڿ��α� ����� : ln%s = %.12f\n\n", num, ae);
			printf("���α� ����� : log%s = %.12f\n\n", num, a10);
			printf("�Ҽ��� ���� ��ȿ���� ���� : %d��\n\n", b);
		back3:
			printf("����Ͻ÷��� 0��, �����Ͻ÷��� �ƹ� ���ڳ� �Է����ּ���. : ");
			scanf("%d", &keep);
			printf("\n\n");
			if (keep == 0)
				continue;
			else
			{
				printf("=================================================================================================\n\n");
				printf("���α׷��� �����մϴ�.\n");
				printf("=================================================================================================\n\n");
				break;
				return 0;
			}
		}
	}

	return 0;
}