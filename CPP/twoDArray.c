#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int **Alloc2DArray(int row, int col){
	int header = row * sizeof(int*);
	int data = row*col*sizeof(int);
	int **rowptr = (int**)malloc(header + data);
	int *buf = (int*)(rowptr + row);
        int i;

	for(i=0;i<row;i++){                                                                                                                                                                                                                                                                            
		rowptr[i] = buf + i*col;
	}
	return rowptr;
}

int main(int argc, char *argv[]){
  int rows=atoi(argv[1]);
  int cols=atoi(argv[2]);
  int i, j;
  int **arr = Alloc2DArray(rows,cols);
  for(i=0;i<rows;i++)
	  for(j=0;j<cols;j++){
		  arr[i][j] = i + j;
	  }

	  for(i=0;i<rows;i++){
	      for(j=0;j<cols;j++){
		      printf("  %d",arr[i][j]);
	    }
		  printf("\n");
	  }
return 0;
}

IP Address: 10.209.17.163(164/165)
Subnet Mask:255.255.254.0
Gatewat:    10.209.16.1