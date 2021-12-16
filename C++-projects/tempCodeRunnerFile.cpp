for (t = 1; t <= p; t++)
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