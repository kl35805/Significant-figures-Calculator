#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(void)
{
	printf("=================================================================================================\n\n");
	printf("---유효숫자 계산기---\n");
	printf("\n");
	printf("***사용 방법***\n\n");
	printf("연산자와 계산할 수를 입력하세요.(계산할 수들을 공백으로 구분해주세요.)\n");
	printf("입력하는 숫자들의 유효 숫자를 판단합니다.\n");
	printf("유효 숫자 계산 법칙에 따라 판단한 유효 숫자를 기반으로 최종 계산값을 결정합니다.\n");
	printf("최종 계산 값과 유효 숫자의 개수가 마지막에 출력됩니다.\n\n");
	printf("=================================================================================================\n\n");
	int choose;
	while (1)
	{
		printf("지수 계산을 원하시면 1번, 사칙연산을 원하시면 2번, 로그 계산을 원하시면 3번을 눌러주세요. : ");
		scanf("%d", &choose);
		printf("\n");
		if (choose != 1 && choose != 2 && choose != 3)
		{
			printf("잘못된 입력입니다. 다시 입력해주세요.");
			printf("\n\n");
			continue;
		}
		if (choose == 1)
		{
			int keep;
			char num[64];
			char under[64];
			printf("밑과 지수를 공백으로 구분하여 입력해주세요. : ");
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
					printf("결과값 : %s ^ %s = %.12f\n\n", under, num, exp);
					printf("유효숫자 개수 : %d개\n\n", k);
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
			printf("결과값 : %s ^ %s = %.12f\n\n", under, num, exp);
			printf("유효숫자 개수 : %d개\n\n", b);
		back1:
			printf("계속하시려면 0을, 종료하시려면 아무 숫자나 입력해주세요. : ");
			scanf("%d", &keep);
			printf("\n\n");
			if (keep == 0)
				continue;
			else
			{
				printf("=================================================================================================\n\n");
				printf("프로그램을 종료합니다.\n");
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
			printf("연산자를 입력해주세요. : ");
			scanf(" %c", &calc);
			printf("\n");
			printf("숫자 2개를 공백으로 구분하여 입력해주세요. : ");
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
			switch (calc) {//일단 최종 결과 값의 유효 숫자 수를 도출할 수 있게 만들었습니다.
			case '+':
				value = atof(num1) + atof(num2);
				printf("결과값 : %s %c %s = %.12lf\n\n", num1, calc, num2, value);
				if (count1 > count2) {
					printf("유효숫자 개수 : %d개\n\n", count2);
				}
				else
					printf("유효숫자 개수 : %d개\n\n", count1);
				break;
			case '-':
				value = atof(num1) - atof(num2);
				printf("결과값 : %s %c %s = %.12lf\n\n", num1, calc, num2, value);
				if (count1 > count2) {
					printf("유효숫자 개수 : %d개\n\n", count2);
				}
				else
					printf("유효숫자 개수 : %d개\n\n", count1);
				break;
			case '*':
				value = atof(num1) * atof(num2);
				printf("결과값 : %s %c %s = %.12lf\n\n", num1, calc, num2, value);
				if (count1 > count2) {
					printf("유효숫자 개수 : %d개\n\n", count2);
				}
				else
					printf("유효숫자 개수 : %d개\n\n", count1);
				break;
			case '/':
				value = atof(num1) / atof(num2);
				printf("결과값 : %s %c %s = %.12lf\n\n", num1, calc, num2, value);
				if (count1 > count2) {
					printf("유효숫자 개수 : %d개\n\n", count2);
				}
				else
					printf("유효숫자 개수 : %d개\n\n", count1);
				break;
			}
			printf("계속하시려면 0을, 종료하시려면 아무 숫자나 입력해주세요. : ");
			scanf("%d", &keep);
			printf("\n\n");
			if (keep == 0)
				continue;
			else
			{
				printf("=================================================================================================\n\n");
				printf("프로그램을 종료합니다.\n");
				printf("=================================================================================================\n\n");
				break;
				return 0;
			}
		}
		if (choose == 3)
		{
			int keep;
			char num[64];
			printf("진수를 입력해주세요 : ");
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
					printf("자연로그 결과값 : ln%s = %.12f\n\n", num, ae);
					printf("상용로그 결과값 : log%s = %.12f\n\n", num, a10);
					printf("소숫점 이하 유효숫자 개수 : %d개\n\n", b);
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
			printf("자연로그 결과값 : ln%s = %.12f\n\n", num, ae);
			printf("상용로그 결과값 : log%s = %.12f\n\n", num, a10);
			printf("소숫점 이하 유효숫자 개수 : %d개\n\n", b);
		back3:
			printf("계속하시려면 0을, 종료하시려면 아무 숫자나 입력해주세요. : ");
			scanf("%d", &keep);
			printf("\n\n");
			if (keep == 0)
				continue;
			else
			{
				printf("=================================================================================================\n\n");
				printf("프로그램을 종료합니다.\n");
				printf("=================================================================================================\n\n");
				break;
				return 0;
			}
		}
	}

	return 0;
}