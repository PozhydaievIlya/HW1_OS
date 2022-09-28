#include <stdio.h>
#include <stdlib.h>
#include <time.h>	//rand
#include <unistd.h>	//sleep
#define SIZE 2


int PlayerCredits = 5000;
int WinCredits = 0;
const int GameCost = 250;
bool JackpotFlag = false;

void outputArray(int a[]){
	printf("Your combination:");
	for (int i=0;i<=sizeof(a)/sizeof(int);i++)
	{		
		printf(" %d ",a[i]);
		}
	printf("\n");

}

void checkComb(int comb[])
{
	int check;
	check = comb[0];
	 
	 switch(comb[0]){
	 
	 	case 0:
	 		if (comb[1]==0)
	 			if (comb[2]==0)
	 			{
	 				WinCredits = 1000;
	 			}
	 		printf("You Win %d credits\n\n", WinCredits);
		 	PlayerCredits = PlayerCredits + WinCredits;	
		 	WinCredits = 0;
	 	break;
	 	
	 	case 1:
	 		if (comb[1]==1)
	 			if (comb[2]==1)
	 			{
	 				WinCredits = 250;
	 			}
	 		printf("You Win %d credits\n\n", WinCredits);
		 	PlayerCredits = PlayerCredits + WinCredits;	
		 	WinCredits = 0;
	 	break;
	 	
	 	case 2:
		 	if (comb[1]==2)
		 		if (comb[2]==2)
		 		{
		 			WinCredits = 300;
		 		}
		 	printf("You Win %d credits\n\n", WinCredits);
		 	PlayerCredits = PlayerCredits + WinCredits;	
		 	WinCredits = 0;
	 	break;
	 	
	 	case 3:
		 	if (comb[1]==3)
		 		if (comb[2]==3)
		 		{
		 			WinCredits = 400;
		 		}
		 	printf("You Win %d credits\n\n", WinCredits);
		 	PlayerCredits = PlayerCredits + WinCredits;	
		 	WinCredits = 0;
	 	break;
	 	
	 	case 4:
		 	if (comb[1]==4)
		 		if (comb[2]==4)
		 		{
		 			WinCredits = 500;
		 		}
		 	printf("You Win %d credits\n\n", WinCredits);
		 	PlayerCredits = PlayerCredits + WinCredits;	
		 	WinCredits = 0;
	 	break;
	 	
	 	case 5:
	 		WinCredits += 100;
		 	if (comb[1]==5)
		 		WinCredits += 100;
		 		if (comb[2]==5)
		 		{
		 			WinCredits += 800;
		 		}
		 	printf("You Win %d credits\n\n", WinCredits);
		 	PlayerCredits = PlayerCredits + WinCredits;	
		 	WinCredits = 0;
	 	break;
	 	
	 	case 6:
		 	if (comb[1]==6)
		 		if (comb[2]==6)
		 		{
		 			WinCredits = -600;
		 			printf("FACE YOUR FATE!!!\n");
		 		}
		 	
		 	printf("You Win %d credits\n\n", WinCredits);
		 	PlayerCredits = PlayerCredits + WinCredits;
		 	WinCredits = 0;
	 	break;
	 	
	 	case 7:
	 		WinCredits += 200;
		 	if (comb[1]==7)
		 	WinCredits += 500;
		 		if (comb[2]==7)
		 		{
		 			printf("Jackpot! ");
		 			JackpotFlag = true;
		 			WinCredits = 1000000;
		 		}
		 	printf("You Win %d credits\n\n", WinCredits);
		 	PlayerCredits = PlayerCredits + WinCredits;	
		 	WinCredits = 0;
	 	break;
	 	
	 	default:
	 		exit(1);
	 }
	
}

int main()
{
	int finalArray[SIZE];
	srand(time(NULL));
	while(PlayerCredits>0)
	{
		printf("//Your Credits: %d \n", PlayerCredits);
		
		if (JackpotFlag == true)
		{
			exit(0);
		}
		
		printf("Game cost: %d  ", GameCost);
		PlayerCredits= PlayerCredits-GameCost;
		if (PlayerCredits<0)
		{
		printf("\n\nYou have run out of credits!\n\n");
			exit(0);
		}
		
		printf("Rolling...  ");
		//sleep(0.5);
		for (int i=0; i<=sizeof(finalArray)/sizeof(int); i++)
		{
			finalArray[i] = rand() %7;
		}
		outputArray(finalArray);
		checkComb(finalArray);
		//sleep(1);
	}
	
	return 0;
}


