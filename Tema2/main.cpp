#include <iostream>
#include <cstdlib>

#include <chrono>
#include <thread>

using namespace std;

#include "Map.h"
#include "Agent1.h"
#include "Handler.h"
#include "Log.h"

int main()
{


	Handler Handler1("input.txt");

//	Handler1.Play(1);
	Handler1.PlaySeq();



}
