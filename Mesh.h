#ifndef _MESH_H

#include <vector>
#include <string>
#include "Dense"
#include "MeshElement.h"

class Mesh
{
  private:
    const std::string _meshname;

    std::vector<Point> _mpoint;
    std::vector<Triangle> _mtriangle;

    // Uniquement les aretes de bord
    std::vector<Edge> _medge;

  public:
    // Constructeur
    Mesh(std::string meshname);

    // ------------------ Lecture et écriture du maillage  ---------------------
    // Lecture du maillage
    void readmesh();
    // Sauvegarde d'un maillage intermédiaire
    void savemesh(std::string outmeshname);
    // Sauvegarde du maillage final
    void savemesh() {std::string outmeshname =
      _meshname.substr(0,_meshname.size()-5)+"_out.mesh"; savemesh(outmeshname);};
    // -------------------------------------------------------------------------
};

#define _MESH_H
#endif
