#include <iostream>
#include <windows.h>

HANDLE opponents[2];

void challengeOpponent(char letters[]) {
	while (1)
	{
    for (char i = 0; letters[i]; ++i)
    {
      std::cout << letters[i] << std::flush;
      Sleep(100);
    }
  }
}

void kenobi(void)
{
  char letters[] = "Grievous!\n";
  challengeOpponent(letters);
}

void grevious(void)
{
  char letters[] = "Kenobi!\n";
  challengeOpponent(letters);
}

int main(void)
{
	opponents[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)kenobi, NULL, 0, NULL);
	opponents[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)grevious, NULL, 0, NULL);
	
	// use INFINITE instead of 5000 to make program run forever
	WaitForMultipleObjects(2, opponents, true, 5000);

	return 0;
}