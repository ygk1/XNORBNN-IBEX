#include "simple_system_common.h"
int pack(int *a[], int column, int row, int width, int init);
int get_act(int act_p, int act_n, int weight);
int main(){

	int weight0[5][6]={1,-1,1,1,1,1,
				-1,1,-1,1,-1,1,
				1,1,1,-1,-1,-1,
				-1,-1,1,1,-1,1,
				1,1,1,1,1,1};
	int weight1[7][6]={1,1,-1,-1,-1,-1,
					-1,-1,1,-1,-1,-1,
					1,-1,1,1,1,1,
					1,1,1,-1,-1,1,
					-1,-1,-1,-1,1,-1
					,-1,1,1,-1,1,-1,
					-1,-1,1,-1,-1,1};
	int weight2[7][6]={-1,-1,-1,1,-1,1
						,1,1,1,1,-1,-1,
						-1,1,-1,1,1,-1,
						1,-1,1,-1,-1,1,
						-1,1,1,1,1,-1,
						1,-1,1,1,1,1,
						1,-1,1,-1,-1,-1};
	int weight3[7][1]={1,-1,1,1,-1,1,1};
	int wb0=-1;
	int wb1=-1;
	int wb2=-1;
	int wb3=-1;
	int input_b,act0,act1,act2;
	int input[275][4]={
	1	,1	,6	,0,
	5	,2	,0	,2
	,0	,-1,	-1,	1
,	-3,	0,	1	,1
	,3	,11,	-3,	-4,
	0	,3	,4	,1,
	5,	4	,-2	,0
	,-4,	6,	1	,-5
,	5	,1	,1	, 1,
	1	,6	,1	,-1
	,-4,	3,	1	,-1
,	-2	,-10	,8	,-1
	,2	,8	,0	,-3
	,0	,9	,1	,-4
	,4	,7	,-1	,0
	,-3,	-7	,1,1	,-1
	,-2,	-7,	8,	1
,	6	,8	,-3	,0
	,5	,-3,	3	,1
	,0	,-1,	0	,1
	,-1,	3,	-4,	-3,
	2	,-5,	9	,-2
,	3	,2	,1	,0,
	4,	1	,1,	1,
	-7,	7,	1	,-8
,	-3,	-1,	4,	1
,	2	,-1,	5	,0
	,-3,	4,	-1,	-4,
	2	,8	,0	,-2
	,3	,6	,-1	,-1
,	-1,	-3,	4,	1
,	5	,8	,-3	,-1
,	0	,1	,-2	,-1
,	5	,10,	-4,	-3,
	5	,8	,-2	,-1
,	2	,0	,6	,0,
	4	,-4,	3	,0
	,1	,4	,-4	,-2
,	1	,6	,2	,0
	,-2,	1,2,	3,	-3,
	-2,	0,	-1,	-1,
	1	,9	,-1	,-2
,	-2,	0,	-1,	0
,	4	,6	,-2	,-1
,	1	,4	,-5	,-3
,	0	,7	,1	,-1
	,-2,	0,	1	,0
	,2	,7	,-1	,-3
,	-4,	-12	,15	,-1
	,-1,	0,	0	,1
	,-1,	2,	0	,-1
,	0	,9	,-4	,-7
,	-2,	1,1, 3,	-3,
	-4,	4,	0	,-2
,	-1,	-6,	5,	1
,	2	,3	,0	,0,
	-1,	9,	2	,-5
,	3	,-3,	2	,0
	,-4,	3,	1	,0
	,-2,	3,	-2,	-2,
	2	,9	,-2	,-2
,	3	,6	,-2	,0
	,-3,	2,	0	,-2
,	1	,8	,-2	,-2
,	3	,2	,2	,1,
	-4,	-13	,13	,-3
	,3	,1	,2	,2,
	4,	-4,	3	,0
	,-2,	-7,	7,	0
,	2	,1	,5	,1,
	-4,	-8,	1,0,	0,
	-2,	8,	-2,	-2,
	1	,1	,6	,0,
	4,	10,	-4,	-4,
	4	,-5,	4	,-1
,	4	,-5,	3	,0
	,-1,	-2,	0,	0
,	2	,8	,-1	,-2
,	-3,	-2,	1,	0
,	4	,1	,2	,1,
	1	,-3,	3	,-1
,	2	,3	,0	,0,
	0	,2	,-3	,-1
,	1	,9	,-2	,-1
,	-2,	1,	0	,-1
,	5	,4	,-1	,1
	,-1,	1,2,	0,	-7,
	-1,	-1,	2,	0
,	1	,1	,-2	,0
	,-2,	1,	9	,1
	,4	,7	,-2	,-1
,	3	,9	,-3	,-1
,	5	,10,	-4,	-4,
	4	,-4,	4	,1
	,-2,	-10	,8	-2,
	-1,	9,	2	,-5
,	3	,2	,3,	1,
	-2,	4,	-1,	-1,
	3	,7	,-1	,0
	,-2,	1,2	,3,	-4,
	-3,	-7,	9,	2
,	4	,11,	-5,	-4,
	2	,4	,1,	0,
	1	,4	,-4	,-2
,	5	,11,	-4,	-4,
	3	,3	,2	,0,
	-1,	1,	-2,	0
,	1	,8	,0,	-2
	,2	,4	,1	,0,
	1,	4	,-5	,-4
,	2	,7	,-1	,-2
,	-4,	2,	1	,-1
,	3	,-3,	3	,-1
,	3	,-5,	4	,-1
,	0	,9	,1,	-4
	,0	,7	,2	,-1
	,0	,2	,-2	,-1
,	1	,5	,-5	,-6
,	5	,4	,-1	,1
	,2	,10,	-3,	-3,
	3	,0	,1	,0,
	4,	-2,	2	,0
	,2	,-7,	8	,-1
,	0	,0	,0	,0,
	4,	9	,-5	,-4
,	-3,	-12	,12	,-2,
	5	,11,	-5,	-4,
	1	,1	,6	,0,
	-3,	-6,	6,	1
,	1	,6	,0	,0,
	0,	8	,1	,-4
	,-2,	-6,	5,	0
,	0	,8	,-3	,-3
,	3	,10,	-4,	-4,
	0	,7	,1	,-1
	,4	,-3,	2	,1
	,0	,9	,2	,-4
	,3	,-3,	2	,0
	,3	,-3,	2	,0
	,4	,-3,	2	,0
	,-2,	1,	0	,-1
,	0	,6	,1	,-1
	,-3,	-1,	3,	0
,	-1,	-2,	0,	0
,	1	,7	,1	,-1
	,-5,	7,	0	,-7
,	-2,	1,2	,2,	-5,
	2	,7	,1	,1,
	1	,0	,6	,-1
	,-2,	-1,	3,	0
,	-3,	-10	,9	,-2
	,-6,	9,	0	,-6
,	4	,-3,	2	,1
	,-2,	-2,	2,	0
,	1	,7	,-2	,-3
,	-4,	2,	0	,-2
,	-5,	-6,	1,1	,-1,
	-4,	4,	0	,-4
,	-1,	1,1	,2,	-4,
	1	,-4,	6	,-1
,	0	,1	,-1	,1
	,3	,9	,-3	,-1
,	0	,-1,	0	,1
	,-4,	3,	1	,-1
,	2	,9	,-2	,-1
,	0	,1	,-1	,1
	,1	,1	,-2	,1
	,0	,7	,2	,-1
	,0	,2	,-3	,-1
,	-1,	-2,	3,	1
,	-1,	3,	-2,	-2,
	-2,	-1,	3,	0
,	3	,4	,1,	0,
	-2,	1,2,	0,	-8,
	3	,3	,1	,0,
	-3,	-9,	1,0	,0,
	-2,	-2	,2,	1
,	-5,	3,	1	,-1
,	1	,8	,-2	,-2
,	0	,3	,-4	,-3
,	5	,5	,-3	,-1
,	4	,11,	-4,	-4,
	-1,	0,	0	,0
	,-4,	-8,	1,2	,-1,
	1	,8	,2	,-3
	,3	,-3,	3	,0
	,2	,7	,-1	,-1
,	4	,3	,1	,1,
	4	,-5,	3	,-1
,	1	,11,	-1,	-4,
	-3,	-1	,3,	1
,	0	,3	,-4	,-3
,	5	,-4,	3	,0
	,2	,4	,-5	,-3
,	1	,8	,1	,-3
	,4	,7	,-1	,0
	,-4,	-13	,13	,-3
	,5	,0	,0,	0,
	4,	11,	-4,	-5,
	4	,0	,2,	2,
	-4,	-13	,16	,-1,
	1	,2	,4	,0,
	5	,1	,0,	2,
	3	,10,	-3,	-3,
	-1,	3,	-1,	-2,
	-2,	3,	-1,	-2,
	1	,9	,-1	,-2
,	4	,0	,1	,1,
	0	,9	,-4	,-7
,	0	,4	,-4	,-4
,	4	,3	,1	,1,
	3,	1	,2	,2,
	2,	0	,5	,1,
	4,	8	,-2	,-1
,	-1,	2,	8	,1
	,1	,-3,	3	,-1
,	-2,	2,	7	,1
	,4	,10,	-4,	-4,
	-2,	-6,	6,	0
,	-1,	-5,	6,	0
,	-1,	1,	8	,1
	,0	,-1,	1	,1
	,4	,-3,	3	,1
	,-3,	-6,	6,	0
,	2	,6	,1	,0,
	-2,	-7	,8,	1
,	-1,	-1,	0,	0
,	2	,4	,-5	,-3
,	4	,2	,2,	1,
	-3,	-7,	9,	2
,	0	,-1,	7	,0
	,2	,-6,	8	,0
	,-3,	2,	1	,0
	,-2,	1,2	,3,	-5,
	0	,0	,-1	,0
	,2	,4	,-4	,-2
,	-1,	1,0	-3,	-6,
	1	,6	,2	,0,
	1	,9	,-2	,-2
,	-2,	-7	,5,	0
,	3	,8	,0	,-2
	,-4,	-8,	1,0, 1,
	-1,	3,	-1,	-2,
	4	,1	,2,	2,
	-1,	2,	7	,1
	,0	,9	,1,	-4
	,-4,	-13	,17	,-3,
	-1,	3,	-1,	-1,
	-2,	-8,	9,	1
,	-1,	2,	-1,	-1,
	0	,7	,1	-1
	,3	,7	,0	,0,
	-1,	2,	0	,-1
,	6	,10,	-5,	-4,
	-2,	-9,	9,	-1,
	5	,8	,-2	,-1
,	-2,	-6,	6,	0
,	3	,11,	-3,	-4,
	-4,	3,	-1,	-4,
	1	,4	,3	,0,
	2,	7	,0	,-2
	,6	,6	,-3	,-1
,	1	,4	,-5	,-3
,	-6,	7,	1	,-7
,	3	,7	,-1	,0
	,1	,9	,-1	,-2
,	-2,	-7,	6,	0
,	1	,-1,	7	,-1
,	0	,-4,	2	,1
	,-2,	-7,	7,	0
,	-3,	-2,	2,	0
,	2	,10,	-3,	-3,
	1	,1	,6	,-1
	,1	,6	,2	,0,
	1	,1	,-1	,0};
	int out_actual[275]={0,0,1,1,0,0,0,1,0,0,1,1,0,0,0,1,1,0,0,1,1,0,0,0,1,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0,1,1,1,0,0,1,1,0,0,0,1,1,0,0,1,0,0,1,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,1,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,1,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,0,0,1,1,1,0,1,0,1,1,1,0,0,1,0,1,1,0,1,1,0,1,1,1,1,0,0,0,1,1,1,0,1,0,0,1,1,0,0,0,0,0,0,1,1,0,1,0,0,1,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,1,0,1,0,1,1,1,0,1,0,0,1,0,1,1,0,0,0,1,0,1,1,0,0,0,1,1,1,1,0,0,1,0,1,0,1,0,1,0,0,0,1,1,0,0,1,0,1,1,1,0,0,0,1
};
	int out[275];
	int i,j, l;
	int counter=0;
	for (i=0; i<275; i++){
		for(l=0; l<4; l++){
		//binarized the input row
		asm volatile(
				"pack	%[z], %[x], %[y]\n\t"
					: [z] "=r" (input_b)
					: [x] "r" (input_b), [y] "r" (input[i][l])
		);
		}
		asm volatile(
				"pack	%[z], %[x], %[y]\n\t"
					: [z] "=r" (input_b)
					: [x] "r" (input_b), [y] "r" (1)
		);
		//compute hidden layer1
		for(j=0; j<6; j++){
			wb0=pack((int**) weight0, j, 5, 6,-1);
			act0=get_act(input_b, act0, wb0);

		}
		//add bias
		asm volatile(
				"pack	%[z], %[x], %[y]\n\t"
					: [z] "=r" (act0)
					: [x] "r" (act0), [y] "r" (1)
		);

		//compute hidden layer 2
		for(j=0; j<6; j++){
			wb1=pack((int**) weight1, j, 7, 6,-1);
			act1=get_act(act0, act1, wb1);

		}
		//add bias
		asm volatile(
				"pack	%[z], %[x], %[y]\n\t"
					: [z] "=r" (act1)
					: [x] "r" (act1), [y] "r" (1)
		);

		//compute hidden layer 3
		for(j=0; j<6; j++){
			wb2=pack((int**) weight2, j, 7, 6,-1);
			act2=get_act(act1, act2, wb2);

		}
		//add bias
		asm volatile(
				"pack	%[z], %[x], %[y]\n\t"
					: [z] "=r" (act2)
					: [x] "r" (act2), [y] "r" (1)
		);
		wb3=pack((int**) weight3, 0, 7, 1,-1);
		out[i]=get_act(act2, out[i], wb3);
		if(out[i]==out_actual[i])
			counter+=1;

	}
	puthex(counter);
	return 0;


}
int pack(int *a[], int column, int row, int width, int init){
	int bin_a=init;
	int i;
	for(i=0; i<row; i++){
			//puthex(*((a+i*(width))+column));
			asm volatile(
				"pack	%[z], %[x], %[y]\n\t"
					: [z] "=r" (bin_a)
					: [x] "r" (bin_a), [y] "r" (*((a+i*(width))+column))
		);


		}

	return bin_a;
}
int get_act(int act_p, int act_n, int weight){
	int xnor_temp;
	int pack_temp;
	int pcnt_temp;
	asm volatile(
				"xnor	%[z], %[x], %[y]\n\t"
					: [z] "=r" (xnor_temp)
					: [x] "r" (act_p), [y] "r" (weight)
			);
	asm volatile(
				"pcnt	%[z], %[x]\n\t"
					: [z] "=r" (pcnt_temp)
					: [x] "r" (xnor_temp)
		);

	asm volatile(
				"pack	%[z], %[x], %[y]\n\t"
					: [z] "=r" (pack_temp)
					: [x] "r"  (act_n), [y] "r" (pcnt_temp)
		);
	return pack_temp;
}
