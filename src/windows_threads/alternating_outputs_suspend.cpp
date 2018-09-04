#include <iostream>
#include <windows.h>

HANDLE opponents[2];

void challengeOpponent(char letters[], char self, char opponent) {
  while (1)
	{
    SuspendThread(opponents[opponent]);

    for (char i = 0; letters[i]; ++i)
    {
      std::cout << letters[i] << std::flush;
      Sleep(100);
    }

    while (ResumeThread(opponents[opponent]) - 1);
    SuspendThread(opponents[self]);
  }
}

void kenobi(void)
{
  char letters[] = "Grievous!\n";
  challengeOpponent(letters, 0, 1);
}

void grevious(void)
{
  char letters[] = "Kenobi!\n";
  challengeOpponent(letters, 1, 0);
}

int main(void)
{
	opponents[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)kenobi, NULL, 0, NULL);
	opponents[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)grevious, NULL, 0, NULL);
	
	// use INFINITE instead of 6000 to make program run forever
	WaitForMultipleObjects(2, opponents, true, 6000);

	return 0;
}