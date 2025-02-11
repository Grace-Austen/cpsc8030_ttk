/// TODO 4: Provide your information and **update** the documentation (in
/// particular regarding the order convention if input arrays need to be
/// specified with the standard VTK call SetInputArrayToProcess()).
///
/// \ingroup vtk
/// \class ttkPackageMergeTrees
/// \author Grace Austen <gausten@clemson.edu>
/// \date April 22, 2024
///
/// \brief TTK VTK-filter that wraps the ttk::PackageMergeTrees module.
///
/// This VTK filter uses the ttk::PackageMergeTrees module to take in n merge trees
/// and formats them so they can be used by MergeTreeClustering
///
/// \param Input vtkMultiBlockDataSet that contains the merge tree in the format vtkMultiBlockDataSet -> block0, block1, block2 where these blocks represent node, arc, segmentation respectively.
/// \param Output vtkMultiBlockDataSet containing all the merge trees.
///
/// This filter can be used as any other VTK filter (for instance, by using the
/// sequence of calls SetInputData(), Update(), GetOutputDataObject()).
///
/// The input data array needs to be specified via the standard VTK call
/// vtkAlgorithm::SetInputArrayToProcess() with the following parameters:
// / \param idx 0 (FIXED: the first array the algorithm requires)
// / \param port 0 (FIXED: first port)
// / \param connection 0 (FIXED: first connection)
// / \param fieldAssociation 0 (FIXED: point data)
// / \param arrayName (DYNAMIC: string identifier of the input array)
///
/// See the corresponding standalone program for a usage example:
///   - standalone/PackageMergeTrees/main.cpp
///
/// See the related ParaView example state files for usage examples within a
/// VTK pipeline.
///
/// \sa ttk::PackageMergeTrees
/// \sa ttkAlgorithm

#pragma once

// VTK Module
#include <ttkPackageMergeTreesModule.h>

// VTK Includes
#include <ttkAlgorithm.h>

/* Note on including VTK modules
 *
 * Each VTK module that you include a header from needs to be specified in this
 * module's vtk.module file, either in the DEPENDS or PRIVATE_DEPENDS (if the
 * header is included in the cpp file only) sections.
 *
 * In order to find the corresponding module, check its location within the VTK
 * source code. The VTK module name is composed of the path to the header. You
 * can also find the module name within the vtk.module file located in the same
 * directory as the header file.
 *
 * For example, vtkSphereSource.h is located in directory VTK/Filters/Sources/,
 * so its corresponding VTK module is called VTK::FiltersSources. In this case,
 * the vtk.module file would need to be extended to
 *
 * NAME
 *   ttkPackageMergeTrees
 * DEPENDS
 *   ttkAlgorithm
 *   VTK::FiltersSources
 */

// TTK Base Includes
#include <PackageMergeTrees.h>

class TTKPACKAGEMERGETREES_EXPORT ttkPackageMergeTrees
  : public ttkAlgorithm // we inherit from the generic ttkAlgorithm class
  ,
    protected ttk::PackageMergeTrees // and we inherit from the base class
{
private:
  /**
   * TODO 5: Add all filter parameters only as private member variables and
   *         initialize them here.
   */
  // std::string OutputArrayName{"AveragedScalarField"};

public:
  /**
   * TODO 6: Automatically generate getters and setters of filter
   *         parameters via vtkMacros.
   */
  // vtkSetMacro(OutputArrayName, const std::string &);
  // vtkGetMacro(OutputArrayName, std::string);

  /**
   * This static method and the macro below are VTK conventions on how to
   * instantiate VTK objects. You don't have to modify this.
   */
  static ttkPackageMergeTrees *New();
  vtkTypeMacro(ttkPackageMergeTrees, ttkAlgorithm);

protected:
  /**
   * TODO 7: Implement the filter constructor and destructor
   *         (see cpp file)
   */
  ttkPackageMergeTrees();
  ~ttkPackageMergeTrees() override = default;

  /**
   * TODO 8: Specify the input data type of each input port
   *         (see cpp file)
   */
  int FillInputPortInformation(int port, vtkInformation *info) override;

  /**
   * TODO 9: Specify the data object type of each output port
   *         (see cpp file)
   */
  int FillOutputPortInformation(int port, vtkInformation *info) override;

  /**
   * TODO 10: Pass VTK data to the base code and convert base code output to VTK
   *          (see cpp file)
   */
  int RequestData(vtkInformation *request,
                  vtkInformationVector **inputVector,
                  vtkInformationVector *outputVector) override;
};
