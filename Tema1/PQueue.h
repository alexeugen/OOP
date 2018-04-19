struct vheap{
  int val;
  int pon;
};

class PQueue{
public:
  PQueue();
  ~PQueue();
  void insert(int va, int p);
  void extract();
  void Print();

private: //FUNCTIONS
  void max_heapify(int i);
  void max_heap();

        //VARIABLES
  vheap *v;
  int n;

};
