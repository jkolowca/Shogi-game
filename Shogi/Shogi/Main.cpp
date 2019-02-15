#include "Application.h"

int main(){

	Application Application;

	while (!Application.GetWindow()->IsDone()){
		Application.Update();
		Application.Render();
	}

	return 0;
}