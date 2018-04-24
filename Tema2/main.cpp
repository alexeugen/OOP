#include <iostream>
#include <cstdlib>

#include <chrono>
#include <thread>

using namespace std;

#include "Map.h"
#include "Agent1.h"
#include "Handler.h"

int main()
{


	Handler Handler1("input.txt");

	Handler1.Play(4);

}
