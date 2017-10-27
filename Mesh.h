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

//création classe Quadtree
class QuadTree
{
  public:
    //Reference du QuadTree
    int id;
    //Vecteur index, combien de points dans le QuadTree
    Eigen::VectorXi _treegridindex;
    //Vecteur position
    Eigen::VectorXi _treegridposition;
    //Vecteur origine du QuadTree
    Eigen::Vector2i _treegridorigin;
    //Fonction pour subdivisé un quadtree en 4
    void subdivide();

  private:
  // Enfants
  //QuadTree* 3; //northwest
  //QuadTree* 2; //northeast
  //QuadTree* 1; //southEast
  //QuadTree* 0; //southWest

}

//Vecteur treegrid caractérisant un carré
std::vector< QuadTree > _treegrid;

#define _MESH_H
#endif
