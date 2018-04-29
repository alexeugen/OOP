#include "Log.h"

Log::Log()
{
  _logs = new char*[100];
  _nrlogs = 0;

}

Log::~Log()
{

  for(int i = 0; i < _nrlogs; i++)
    delete[] _logs[i];
  delete[] _logs;
}


void Log::Add(char *s)
{
  _logs[_nrlogs] = new char[strlen(s) + 1];
  strcpy(_logs[_nrlogs], s);
  _nrlogs++;
}

void Log::AddDied(char* i)
{

  char *s;
  s = new char[100];
  strcpy(s, "Agent ");
  strcat(s, i);
  strcat(s, " died.");

  _logs[_nrlogs] = new char[strlen(s) + 1];
  strcpy(_logs[_nrlogs], s);
  _nrlogs++;

  delete[] s;
}

void Log::AddMoved(char *i, char* l, char* c)
{

    char *s;
    s = new char[100];
    strcpy(s, "Agent ");
    strcat(s, i);
    strcat(s, " moved to position: ");
    strcat(s, l);
    strcat(s, " ");
    strcat(s, c);

    _logs[_nrlogs] = new char[strlen(s) + 1];
    strcpy(_logs[_nrlogs], s);
    _nrlogs++;

    delete[] s;
}

void Log::AddShielded(char *c)
{
  char *s;
  s = new char[100];
  strcpy(s, "Agent ");
  strcat(s, c);
  strcat(s, " got a shield");

  _logs[_nrlogs] = new char[strlen(s) + 1];
  strcpy(_logs[_nrlogs], s);
  _nrlogs++;

  delete[] s;
}
void Log::AddBlocked(char *c)
{
  char *s;
  s = new char[100];
  strcpy(s, "Agent ");
  strcat(s, c);
  strcat(s, " blocked with shield");

  _logs[_nrlogs] = new char[strlen(s) + 1];
  strcpy(_logs[_nrlogs], s);
  _nrlogs++;

  delete[] s;
}

void Log::AddExtended(char *c)
{
  char *s;
  s = new char[100];
  strcpy(s, "Agent ");
  strcat(s, c);
  strcat(s, " extended his moves");

  _logs[_nrlogs] = new char[strlen(s) + 1];
  strcpy(_logs[_nrlogs], s);
  _nrlogs++;

  delete[] s;
}

void Log::AddBrainy(char *c)
{
  char *s;
  s = new char[100];
  strcpy(s, "Agent ");
  strcat(s, c);
  strcat(s, " got brain");

  _logs[_nrlogs] = new char[strlen(s) + 1];
  strcpy(_logs[_nrlogs], s);
  _nrlogs++;

  delete[] s;
}

void Log::Print()
{
  for(int i = 0; i< _nrlogs; i++)
    cout << _logs[i]<<endl;
}
