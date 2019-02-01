// AUTHORS: Po, Justin Andre
//			Manzanares, Gabriel John

#include <stdio.h>

int main() {
	// declarations
    int arr[20], i, count, temp, x=0, y=0;
    int freq[11] = {0,0,0,0,0,0,0,0,0,0,0};
    
	// asks user for input
    printf("Enter 20 postive integers: \n");
    
    for(i=0, count=0; i<20; i++) {
        
        do {
           scanf("%i", &arr[i]);
        } while (arr[i] < 0);
        
        temp = arr[i];

		// stores frequencies
        if(temp == 0)
            count = 1;
        else
            while(temp != 0) {
                temp/=10;
                count++;
            }        
        
        freq[count]++;
        count = 0;
    }
    
    // finds the first non-negative integer
    for(i=1; x==0; i++) {
        x = freq[i];
        y = freq[i];
    }
    
    // prints the frequency of each digit and stores the most and least frequent
    for(i=1; i<11; i++) {
        
        printf("\nDigit: %i\n", i);
        printf("Frequency: %i\n", freq[i]);
        
        if(x < freq[i]) {
            x = freq[i];
        }
        
        if(y > freq[i] && freq[i] != 0) {
            y = freq[i];
        }
    }
    
    // prints the most frequent digits
    printf("\nMost frequent digits: ");
    
    for(i=1; i<11; i++) {
        
        if(freq[i] == x)
            printf("%i ", i);
    }
    
    // prints the least frequent digits
    printf("\nLeast frequent digits: ");
    
    for(i=1; i<11; i++) {
        
        if(freq[i] == y)
            printf("%i ", i);
    }
    
    printf("\n");
}
