#ifndef _MESH_RAW_CPP

#include "Mesh.h"
#include <fstream>
#include <iostream>
#include <assert.h>

using namespace std;
using namespace Eigen;

void Mesh::readmesh()
{
  ifstream mesh_file(_meshname.data());
  if (!mesh_file.is_open())
  {
    cout << "Impossible d'ouvrir le fichier " << _meshname << endl;
    abort();
  }
  string file_line;
  Vector3d vert; Vector3i tri; Vector2i edg;
  int ref(0), loop_pts(1);
  int np;
  int ned;
  Vector3d treelenght, treeorigin;
  treeorigin <<  1e14, 1e14,0.;
  treelenght << -1e14,-1e14,1.;
  
  while (!mesh_file.eof())
  {
    getline(mesh_file, file_line);
    if ((file_line.find("Vertices") != string::npos)&&(loop_pts))
    {
      mesh_file >> np;
      cout << "Nombre de points  (" << np << ")" << endl;
      for (int i = 0 ; i < np ; ++i)
      {
        mesh_file >> vert[0] >> vert[1] >> vert[2] >> ref;
        // coor, ref, exist, nxt = 0, tmp = 0
        _mpoint.push_back(Point(vert, ref));
        if (treeorigin[0] > vert[0]) { treeorigin[0] = vert[0]; }
        if (treeorigin[1] > vert[1]) { treeorigin[1] = vert[1]; }
        if (treelenght[0] < vert[0]) { treelenght[0] = vert[0]; }
        if (treelenght[1] < vert[1]) { treelenght[1] = vert[1]; }
      }
      loop_pts = 0;
    }
    if (file_line.find("Edges") != string::npos)
    {
      mesh_file >> ned;
      cout << "Nombre d'arêtes (" << ned << ")" << endl;
      for (int i = 0 ; i < ned ; ++i)
      {
        mesh_file >> edg[0] >> edg[1] >> ref;
        edg[0]--; edg[1]--;
        // v, ref, exist, inmesh
        _medge.push_back(Edge(edg, ref));
      }
    }
    if (file_line.find("Triangles") != string::npos)
    {
      cout << "Erreur: on attend un maillage sans triangles !" << endl;
      assert(0);
    }
  }

  treelenght -= treeorigin;
  treelenght[0] += treelenght[0]/5.;
  treelenght[1] += treelenght[1]/5.;
  treeorigin[0] -= treelenght[0]/10.;
  treeorigin[1] -= treelenght[1]/10.;

  for (int i = 0 ; i < np ; ++i)
  {
    _mpoint[i].Modifycoor( (_mpoint[i].Getcoor() - treeorigin) );
    _mpoint[i].Modifycoor( _mpoint[i].Getcoor().array() / treelenght.array() );
  }
}

void Mesh::savemesh(string outmeshname)
{
  ofstream outmesh;
  outmesh.open(outmeshname, ios::out);

  outmesh << "MeshVersionFormatted 2" << endl;
  outmesh << "Dimension 3" << endl;

  outmesh << "Vertices" << endl;
  outmesh << _mpoint.size() << endl;
  for (int i = 0 ; i < _mpoint.size() ; ++i)
  {
    outmesh << _mpoint[i].Getcoor()[0] << " " << _mpoint[i].Getcoor()[1] << " "
    << _mpoint[i].Getcoor()[2] << " " << _mpoint[i].Getref() << endl;
  }
  outmesh << endl;

  outmesh << "Triangles" << endl;
  outmesh << _mtriangle.size() << endl;
  for (int i = 0 ; i < _mtriangle.size() ; ++i)
  {
    outmesh << _mtriangle[i].Gettriangle()[0]+1 << " " << _mtriangle[i].Gettriangle()[1]+1
      << " " << _mtriangle[i].Gettriangle()[2]+1 << " " << _mtriangle[i].Getref() << endl;
  }
  outmesh << endl;
}

#define _MESH_RAW_CPP
#endif
