#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

int main()
{
	int input;

	scanf("%d", &input);

	if (input % 2 == 0)
	{
		int pow = 1;
		printf("2");
		input /= 2;

		while (input % 2 == 0)
		{
			input /= 2;
			pow++;
		}

		if (pow > 1)
			printf("^%d", pow);
	}

	if (input > 2)
		printf(" * ");

	for (int div = 3; div < sqrt(input);)
	{
		if (input % div == 0)
		{
			int pow = 1;
			printf("%d", div);
			input /= div;
		
			while (input % div == 0)
			{
				input /= div;
				pow++;
			}

			if (pow > 1)
				printf("^%d", pow);

			if (input > div)
				printf(" * ");
		
		}
		else
		{
			div++;
		}
	}

	if (input > 1)
		printf("%d", input);

	return 0;
}
