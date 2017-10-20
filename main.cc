#include <iostream>
#include <fstream>
#include "Mesh.h"

using namespace std;
using namespace Eigen;

// -----------
// |  3  |  2  |
// |     |     |
// -----------
// |  0  |  1  |
// |     |     |
// -----------


int main(int argc, char** argv)
{
  if (argc < 2)
  {
    cout << "Please, enter the name of your mesh." << endl;
    abort();
  }
  const string meshname = argv[1];

  // ---------------------------- Lecture du maillage  -------------------------
  cout << "------------------------------------------------------------------" << endl;
  cout << "Lecture du maillage " << meshname << endl;
  cout << "------------------------------------------------------------------" << endl;
  Mesh* mesh = new Mesh(meshname);
  mesh->readmesh();
  cout << "------------------------------------------------------------------" << endl;
  // ---------------------------------------------------------------------------

  // --------------------------- Sauvegarde du maillage  -----------------------
  cout << "------------------------------------------------------------------" << endl;
  cout << "Sauvegarde du maillage " << meshname << endl;
  cout << "------------------------------------------------------------------" << endl;
  mesh->savemesh();
  cout << "------------------------------------------------------------------" << endl;
  // ---------------------------------------------------------------------------

  return 0;
}
