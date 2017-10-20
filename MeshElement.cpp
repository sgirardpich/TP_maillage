#ifndef _MESH_EL_CPP

#include "Mesh.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include <assert.h>

using namespace std;
using namespace Eigen;

Point::Point(Vector3d coor, int ref)
: _coor(coor), _ref(ref) {}

Edge::Edge(Vector2i v, int ref)
: _v(v), _ref(ref) {}

Triangle::Triangle(Vector3i v, int ref)
: _v(v), _ref(ref) {}

#define _MESH_EL_CPP
#endif
