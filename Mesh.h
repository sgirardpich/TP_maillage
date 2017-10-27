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
    //Vecteur treegrid caractérisant un carré
    std::vector< QuadTree > _treegrid;


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
    //Construteur du quadtree
    Quadtree(Eigen::VectorXi treegridpoints, Eigen::VectorXi treegridposition, Eigen::Vector2i treegridorigin)
    //Fonction pour subdivisé un quadtree en 4
    void subdivide();
    //Récupère la référence de la position du Quadtree
    Eigen VectorXi Getref(){return _treegridposition};
    //Récupère les coordonnées de l'origine du QuadTree
    Eigen Vector2i Getorigin(){return _treegridorigin};
    //Récupère le nmbr de points dans le QuadTree
    Eigen VectorXi Getnbr(){return _treegridpoints};
  private:
    //Vecteur index, combien de points dans le QuadTree
    Eigen::VectorXi _treegridpoints;
    //Vecteur position
    Eigen::VectorXi _treegridposition;
    //Vecteur origine du QuadTree
    Eigen::Vector2i _treegridorigin;

}


#define _MESH_H
#endif
