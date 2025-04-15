#include <conio.h>
#include <stdio.h>
#include <dos.h>

int main() {
	int seconds = 0;
	printf("Time: ");
	while (!kbhit()) {
		gotoxy(7,1);
		printf("%d sec", seconds);
		delay(1);
		seconds++;
	}
	return 0;
}