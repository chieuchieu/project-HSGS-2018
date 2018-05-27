#include <stdio.h>
#include <stdlib.h>

/* During the BOI'99 the following maximum points for test cases were given:
const testcount = 15;
const int points[testcount+1] = {0,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3};
*/

const MAX_C = 200;
const MAX_R = 100;

int C,R;
int M[MAX_C][MAX_R];
int ok[MAX_R];

void main(){
	FILE *in = fopen("lazy.in","rt");
	if (in == NULL){
		printf("Cant open input file!\n");
		exit(101);
	}

	if (fscanf(in,"%d %d",&C,&R) != 2){
		printf("Incorrect input file!\n");
		exit(101);
	}
	for (int i = 0; i < C; i++)
		for (int j = 0; j < R; j++)
			if (fscanf(in,"%d",&M[i][j]) != 1){
				printf("Incorrect input file!\n");
				exit(101);
			}
	fclose(in);

	for (i = 0; i < R; i++) ok[i] = 0;

	FILE *out = fopen("lazy.out","rt");
	if (out == NULL){
		printf("Cant open output file!\n");
		exit(103);
	}

	int N;
	if (fscanf(out,"%d",&N) != 1){
		printf("Integer number expected!\n");
		exit(102);
	}
	if (N > C){
		printf("Incorrect solution (N > C)\n");
		exit(102);
	}

	for (i = 0; i < N; i++){
		int cNum;
		if (fscanf(out,"%d",&cNum) != 1){
			printf("Integer number expected!\n");
			exit(102);
		}
		if (cNum < 1 || cNum > C){
			printf("Incorrect course number!\n");
			exit(102);
		}
		cNum--;
		for (int j = 0; j < R; j++)
			if (M[cNum][j] == 1) ok[j] = 1;
	}
	fclose(out);

	for (i = 0; i < R; i++)
		if (ok[i] == 0){
			printf("Requirement not fullfilled!\n");
			exit(102);
		}

	printf("Correct!\n");
	exit(1);
}