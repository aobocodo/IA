#include <signal.h>
void signalRoutine(int);

int main(void){
	printf("signal processing demo program\n");
	while(1){
		signal(SIGINT,signalRoutine);
	}
}

void signalRoutine(int dummy){
	printf("Sinal routine called[%d]\n",dummy);
	exit(0);
}