#include "Manager.h"
int main() {
	Manager mng;
	mng.Menu();
	while (mng.GameIsOn()) {
		mng.DrawGame();
	}
	return 0;
}