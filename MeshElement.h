#ifndef _MESH_EL_H

#include <vector>
#include <string>
#include "Dense"

class Point
{
  private:
     // Coordonnees du point ; rq : en 2D la 3e coord est nulle
     Eigen::Vector3d _coor;
     // Tag associe au point
     int _ref;
  public:
    // Constructeur
    Point(Eigen::Vector3d coor, int ref);
    // Récupérer coor
    Eigen::Vector3d Getcoor() {return _coor;};
    // Modifier coor
    void Modifycoor(Eigen::Vector3d coor) { _coor = coor;};
    // Récupérer la référence du point
    int Getref(){return _ref;};
};

// Sert a priori uniquement pour les arêtes de frontières
class Edge
{
  private:
    // Indices des 2 sommets composant l'arete
    Eigen::Vector2i _v;
    // Tag associe a l'arete
    int _ref;
  public:
    // Constructeur
    Edge(Eigen::Vector2i v, int ref);
    // Récupérer l'arête
    Eigen::Vector2i Getedge(){return _v;};
    // Récupérer la référence de l'arête
    int Getref(){return _ref;};
};

class Triangle
{
  private:
    // Indices des 3 sommets composant le triangle
    Eigen::Vector3i _v;
    // Tag associe au triangle
    int _ref;
  public:
    // Constructeur
    Triangle(Eigen::Vector3i v, int ref);
    // Récupérer le triangle
    Eigen::Vector3i Gettriangle(){return _v;};
    // Modifier v
    void Modifytriangle(Eigen::Vector3i v) {_v = v;};
    // Récupérer la référence du triangle
    int Getref(){return _ref;};
};

#define _MESH_EL_H
#endif
