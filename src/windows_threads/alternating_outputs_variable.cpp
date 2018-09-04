#include <iostream>
#include <windows.h>

HANDLE opponents[2];

int turn = 1;

void challengeOpponent(char letters[], char own_turn, char next_turn) {
	while (1)
	{
    if (turn == own_turn)
    {
      for (char i = 0; letters[i]; ++i)
      {
        std::cout << letters[i] << std::flush;
        Sleep(100);
      }

      turn = next_turn;
    }
  }
}

void kenobi(void)
{
  char letters[] = "Grievous!\n";
  challengeOpponent(letters, 1, 2);
}

void grevious(void)
{
  char letters[] = "Kenobi!\n";
  challengeOpponent(letters, 2, 1);
}

int main(void)
{
	opponents[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)kenobi, NULL, 0, NULL);
	opponents[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)grevious, NULL, 0, NULL);
	
	// use INFINITE instead of 5400 to make program run forever
	WaitForMultipleObjects(2, opponents, true, 5400);

	return 0;
}