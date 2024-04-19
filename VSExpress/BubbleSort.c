//https://www.youtube.com/watch?v=EZN0Irp2aPs&list=PLRx0vPvlEmdDHxCvAQS1_6XV4deOwfVrz&index=3

#include <stdio.h> 

int main() {
	int i, j, min, index, temp;
	int array[10] = {1,10,5,8,7,6,4,3,2,9};

    for(i=0; i<10; i++) {
		for(j=0; j<9-i; j++) {
			if(array[j] > array[j+1]) {
				temp = array[j+1];
				array[j] = array[j+1];
				array[j+1] = temp;
			}

		}
	}

}