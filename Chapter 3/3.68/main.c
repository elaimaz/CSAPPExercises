#include <stdio.h>

void good_echo() {
	char buffer[20];
	char *line;

	while (fgets(buffer, sizeof(buffer), stdin) != NULL)
	{
		printf("%s", buffer);
	}

}

int main() {
	good_echo();
    return 0;
}