#include <stdio.h>
#include <stdlib.h>
int main() {
  int arrSize, ballEnergy, newEnergy, deltaPozitif = 0, counter = 0,
                                      minBallEnergy = 0;
  printf("Enter your lego size: ");
  scanf("%d", &arrSize);
  int arr[arrSize];
  for (int i = 0; i < arrSize; i++) {
    printf("Lego %d.: ", i + 1);
    scanf("%d", &arr[i]);
  }

  for (int x = 0; x < 99; x++) {

    if (ballEnergy < 0) {
      counter = 0;
      deltaPozitif = 0;
    }
    ballEnergy = x;

    for (int j = 0; j < arrSize; j++) {

      if (counter == arrSize) {
        break;
      }

      if (ballEnergy >= arr[j] && ballEnergy >= 0) {

        deltaPozitif = deltaPozitif + (ballEnergy - arr[j]);
        ballEnergy = ballEnergy + (ballEnergy - arr[j]);
        counter++;

        if (counter == arrSize) {

          printf("BallEnergy : %d\n", ballEnergy);
          printf("Delta : %d\n", deltaPozitif);
          minBallEnergy = ballEnergy - deltaPozitif;
          printf("Min. BallEnergy : %d\n ", minBallEnergy);
          break;
        }

      }

      else if (ballEnergy > 0 && ballEnergy < arr[j]) {
        if (ballEnergy < arr[j] && ballEnergy >= 0) {

          deltaPozitif = deltaPozitif + (ballEnergy - arr[j]);
          ballEnergy = ballEnergy + (ballEnergy - arr[j]);

          if (ballEnergy >= 0) {
            counter++;
          }
          if (counter == arrSize) {

            printf("BallEnergy : %d\n", ballEnergy);
            printf("Delta : %d\n", deltaPozitif);
            minBallEnergy = ballEnergy - deltaPozitif;
            printf("Min. BallEnergy : %d\n ", minBallEnergy);
            break;
          }
        }
      } else {
        deltaPozitif = 0;
        ballEnergy = 0;
        counter = 0;
      }
    }
  }
  return 0;
}
