/* This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

// https://github.com/ErayOzdayioglu/CS350 

#include <stdio.h>
#include <stdbool.h>


#define threshold 8

bool dorm(int array[]) {
	for (int i=0;i<5;i++) {
		if (array[i] >= threshold) {
			return 1;
		}
	}

	return 0;
}

int largest(int arr[], int n)
{
    int i;

    // Initialize maximum element
    int max = arr[0];
 	int index=0;
    // Traverse array elements from second and
    // compare every element with current max
    for (i = 0; i < n; i++)
        if (arr[i] > max) {
            max = arr[i];
        	index = i;
        }
 
    return index + 1; 
}


int main() {

	int numberOfPeople;

	printf("What is the number of people \n");

	scanf("%d", &numberOfPeople);

	int foods [5] = {0,0,0,0,0};

	for (int i =0;i< numberOfPeople;i++) {
		printf("What you want ? 1-Kebab, 2-Burger, 3-Pasta, 4-Lahmacun, 5-Salad. Enter in the preference order then press enter\n");
		int c=5;
		int choice;
		while(c>0) {
			
			scanf("%d",&choice);
			// printf("%d\n", choice);
			foods[choice-1] = foods[choice-1] + c;
			// printf("Tamam\n");
			--c;
		}
	}

	printf("--------SECOND ROUND-------\n");

	int counter=0;
	for (int i=0;i<5;i++) {
		if (dorm(foods)) {
		  if (foods[i]>= threshold) {
			printf("Food number: %d - Point: %d \n",i+1,foods[i]);
			counter++;
	    	}
		}
		else {
			printf("You are eating at home/dorm today!\n");
			return 0;
		}
	}

	for (int i =0;i< numberOfPeople;i++) {
		printf("What you want ? Choose from above list. 1-Kebab, 2-Burger, 3-Pasta, 4-Lahmacun, 5-Salad \n");
		
		int choice;
		int c = counter;
		while(c>0) {
			
			scanf("%d",&choice);
			// printf("%d\n", choice);
			foods[choice-1] = foods[choice-1] + c*2;
			// printf("Tamam\n");
			--c;
		}
	}

	for (int i=0;i<5;i++) {
		if (foods[i]>= threshold) {
			printf("Food number: %d - Point: %d \n",i+1,foods[i]);
	    	}
	}

	switch(largest(foods,5)) {
		case 1:
			printf("The chosen food is Kebab\n");
			break;
		case 2:
			printf("The chosen food is Burger\n");
			break;
		case 3:
			printf("The chosen food is Pasta\n");
			break;
		case 4:
			printf("The chosen food is Lahmacun\n");
			break;
		case 5:
			printf("The chosen food is Salad\n");
			break;
		default:
			printf("You chose the wrong food\n");
	}


	return 0;
}