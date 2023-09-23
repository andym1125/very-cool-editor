#include <stdio.h>
#include <ncurses.h>

using namespace std;

int main()
{
	initscr();

    FILE* file = fopen("text.txt", "rb");
	const char filename[] = "text.txt";
	if(file == NULL)
	{
		printf("Fatal error opening file %s", filename);
		return -1;
	}

	const int BUFFER_SIZE = 256;
	char buffer[BUFFER_SIZE];
	int readchars = fread(buffer, sizeof(char), BUFFER_SIZE, file);
	printw(buffer);
	while(readchars == BUFFER_SIZE)
	{
		readchars = fread(buffer, sizeof(char), BUFFER_SIZE, file);
		printw(buffer);
	}
    
	getch();
	fclose(file);
    endwin();
	printf("%d", readchars);
}