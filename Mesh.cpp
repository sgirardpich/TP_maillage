#ifndef _MESH_CPP

#include "Mesh.h"
#include <fstream>
#include <iostream>
#include <assert.h>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace Eigen;

Mesh::Mesh(string meshname)
: _meshname(meshname)
{

}

void QuadTree::subdivide()
{
  n=0
  //boucle sur le nombre d'itération n
  //carré i _treegrid(0)
  // si il y a moins d'un point alors rien
  if else
    _treegrid(n+1)
}

//1ére étape
//numérotation des 4 premiers carrés
_treegrid(0,0)=1
_treegrid(1,0)=2
_treegrid(2,0)=3
_treegrid(3,0)=4
//itération n=0 ; coordonnée n+1
//affactation de leur réfèrence
_treegrid(0,1)=QuadTree0
_treegrid(1,1)=QuadTree1
_treegrid(2,1)=QuadTree2
_treegrid(3,1)=QuadTree3

#define _MESH_CPP
#endif
