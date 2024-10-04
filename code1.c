#include <stdio.h>

void combinations(int score) {
    printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

//series of nested loops to go through possible TDs, FGs, and safeties
    for (int td2 = 0; td2 * 8 <= score; td2++) {
        for (int td1 = 0; td1 * 7 + td2 * 8 <= score; td1++) {
            for (int td = 0; td * 6 + td1 * 7 + td2 * 8 <= score; td++) {
                for (int fg = 0; fg * 3 + td * 6 + td1 * 7 + td2 * 8 <= score; fg++) {
                    for (int safety = 0; safety * 2 + fg * 3 + td * 6 + td1 * 7 + td2 * 8 <= score; safety++) {
                        int total = td2 * 8 + td1 * 7 + td * 6 + fg * 3 + safety * 2;
                        if (total == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG, %d Safety\n", td2, td1, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    while (1) {
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) { //stopping the program if user chooses
            printf('Program is stopping...');
            break;
        }

        combinations(score); // calls the function
    }

    return 0;
}
