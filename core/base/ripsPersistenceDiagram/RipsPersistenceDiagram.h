/// \ingroup base
/// \class ttk::RipsPersistenceDiagram
/// \author Mattéo Clémot <matteo.clemot@univ-lyon1.fr>
/// \date January 2024.
///
/// \brief TTK VTK-filter that computes the persistence diagram of a Rips complex.
///
/// \param Input Input table (vtkTable)
/// \param Output PersistenceDiagram (vtkUnstructuredGrid)
///
/// This module defines the %RipsPersistenceDiagram class that takes a point
/// cloud or a distance matrix (vtkTable) and computes the persistence diagram
/// of its Rips complex.
///
/// \sa ttk::Triangulation
/// \sa ttkRipsPersistenceDiagram.cpp %for a usage example.

#pragma once

// ttk common includes
#include <Debug.h>

#include <ripser.h>

namespace ttk {

  /**
   * The RipsPersistenceDiagram class provides a method to call the code Ripser
   * in order to compute the persistence diagram of the Rips complex of the input.
   */
  class RipsPersistenceDiagram : virtual public Debug {

  public:
    RipsPersistenceDiagram();

    /**
     * @brief Main entry point
     *
     * @param[in] points Input point cloud in any dimension
     * @param[out] ph Computed Rips persistence diagram
     */
    int execute(const std::vector<std::vector<double>> &points, std::vector<std::vector<ripser::pers_pair_t> >& ph) const;

  protected:
    /** Max dimension of computed persistence diagram */
    int MaxDim{1};
    /** Rips threshold */
    double Threshold{1.0};
    /** is input a distance matrix */
    int InputIsDistanceMatrix{0};

  }; // RipsPersistenceDiagram class

} // namespace ttk
