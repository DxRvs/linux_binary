#include <unistd.h>

int main(int argc, char *argv[]) {
		setsid();
		setuid(0);
		setgid(0);
		execl("/bin/bash", "/bin/bash","-c",argv[1], NULL);
	return 0;
}
