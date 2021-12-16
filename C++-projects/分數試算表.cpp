#include <stdio.h>
#include <stdlib.h>
int main()
{
	int score = 0;
	int sum = 0;
	int p = 0;
	int t = 0;
	int max = 0;
	int min = 0;

	printf("請輸入人數 : ");
	while (scanf("%d", &p) == 1)
	{
		if (p > 0)
			break;

		printf("error\n請重新輸入\n請輸入人數 : ");
	}

	for (int t = 1; t <= p; t++)
	{
		printf("請輸入第 %d 的成績 : ", t);
		scanf("%d", &score);

		if (score >= 0 && score <= 100)
		{
			sum += score;

			if (t == 1)
			{
				min = score;
				max = score;
			}
			else if (min > score)
				min = score;
			else if (max < score)
				max = score;
		}
		else
		{
			printf("error\n請重新輸入\n");
			t = t - 1;
		}
	}

	printf("============================================\n");
	printf("最高分為%d\n", max);
	printf("最低分為%d\n", min);
	printf("總成績為%d\n", sum);
	printf("平均為%.2f\n", (float)sum / p);
	printf("全距為%d\n", max - min);

	system("Pause");

	return 0;
}
