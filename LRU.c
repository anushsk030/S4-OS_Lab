#include <stdio.h>

void main() {
    int no_frame, no_request, i, pgf = 0;
    printf("Enter the number of requests\n");
    scanf("%d", &no_request);
    printf("Enter the number of frames\n");
    scanf("%d", &no_frame);
    int frame[no_frame], req[no_request], time[no_frame];
    for(i = 0; i < no_frame; i++) {
        frame[i] = -1;
        time[i] = 0;
    }
    printf("Enter the requests:\n");
    for(i = 0; i < no_request; i++) {
        scanf("%d", &req[i]);
    }
    printf("Page replacement:\n");
    for(i = 0; i < no_request; i++) {
        int avail = 0, least = 0;
        printf("%d :", req[i]);
        for(int a = 0; a < no_frame; a++) {
            if(frame[a] == req[i]) {
                avail = 1;
                time[a] = i + 1;  // Update the time of the page
                break;
            }
        }
        if(avail == 0) {
            for(int a = 1; a < no_frame; a++) {
                if(time[a] < time[least]) {
                    least = a;
                }
            }
            frame[least] = req[i];
            time[least] = i + 1;  // Update the time of the new page
            pgf++;
        }
        for(int a = 0; a < no_frame; a++) {
            printf("%d\t", frame[a]);
        }
        printf("\n");
    }
    printf("No of page faults = %d\n", pgf);
}
