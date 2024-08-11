#include <stdio.h>
#include <stdlib.h>

void main() {
    int head, limit, seektime = 0;

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter number of requests: ");
    scanf("%d", &limit);
    
    int req[limit];

    printf("Enter requests:\n");
    for(int i = 0; i < limit; i++)
        scanf("%d", &req[i]);

    // Calculate total head movement
    for(int i = 0; i < limit; i++) {
        seektime += abs(req[i] - head);
        head = req[i];
    }

    printf("Total Head Movement is %d\n", seektime);
}
