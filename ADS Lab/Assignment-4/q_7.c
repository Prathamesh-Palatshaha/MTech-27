#include <stdio.h>

typedef struct {
    char name[50];
    int runs;
    int wickets;
} Player;

int main() {
    int n;
    printf("Enter number of players: ");
    scanf("%d", &n);

    Player team[n];
    for(int i = 0; i < n; i++) {
        printf("Enter name, runs, and wickets for player %d: ", i+1);
        scanf(" %[^\n]%d%d", team[i].name, &team[i].runs, &team[i].wickets);
    }

    int highestRunsIndex = 0;
    for(int i = 1; i < n; i++) {
        if(team[i].runs > team[highestRunsIndex].runs) {
            highestRunsIndex = i;
        }
    }

    printf("Player with highest runs: %s (%d runs)\n", team[highestRunsIndex].name, team[highestRunsIndex].runs);

    return 0;
}
