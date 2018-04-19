

class Agent1{
public:
  Agent1();
  Agent1(int poz_x, int poz_y);
  ~Agent1();
  void Move();


private:
  void _setAvailable();



  int _poz_x;
  int _poz_y;

  struct poz{
    int x,y;
    /*
    poz(int a, int b)
    {
        x = a;
        y = b;
    }*/
  };

  struct availablePositions{
    poz p[4];

    void Get();
  }_avPos;


};
