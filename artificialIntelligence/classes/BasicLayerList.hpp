#ifndef BASIC_LAYER_LIST_HPP
#define BASIC_LAYER_LIST_HPP

#include <iostream>

#include <coreutils/classes/matrixes/Matrix3D.cuh>
#include "BasicLayer.cuh"

using namespace coreutils::classes::matrixes;
using namespace artificialIntelligence::classes;

namespace artificialIntelligence {
   namespace classes {

      
      class BasicLayerList {
         private:
            // first layer
            BasicLayer* root;

            // last layer
            BasicLayer* last;

         public:
            // -- CONSTRUCTOR DESTRUCTOR COPY -- //

            // constructors
            BasicLayerList (Matrix3D* layer, Matrix3D* biasMatrix = nullptr, BasicWeight* weights = nullptr);
            BasicLayerList ();
            
            // destructor
				~BasicLayerList ();

            // copy constructor
				BasicLayerList(const BasicLayerList& bll);


            // -- GET METHODS -- //

            // gets the root layeer
            BasicLayer* getRoot ();

            // gets the last layer
            BasicLayer* getLast ();

            // -- SET METHODS -- //
            
            // sets the root matrix
            void editRootMatrix (Matrix3D* newMatrix);


            // -- GENERATE METHODS -- //

            // adds a layer at the end of the model recursively 
            void add (BasicLayer* layer);

            // creates and adds a layer at the end of the model recursively
            void add (Matrix3D* layer, Matrix3D* biasMatrix = nullptr, BasicWeight* weights = nullptr);

            // creates and adds a layer at the end of the model recursively
            void addNew (int length, int width, int height);


            // -- LAYER UPDATE METHODS -- //
            
            // updates all layers in the model using CPU compute
            void calculateAndUpdateAllCPU ();

            // updates the last layer using CPU compute
            void calculateAndUpdateLastCPU ();

            // updates all layers in the model using GPU compute revised
				void calculateAndUpdateAllGPUV2 ();


            // -- PRINT METHODS -- //
            
            // prints the layer and all layers below it
            void print (bool printBias = false, bool printWeights = false);


            // -- LOAD AND UNLOAD FILE METHODS -- //

            // loads a model into a file using the format of 
            // layer length, layer width, layer height
            // bias length, bias width, bias height
            // <the values for the bias, all comma seperated>
            // layer length, layer width, layer height, bias length, bias width, bias height
            // <the values for the weights, with each float16 represented by 4 bytes of data> 
            void toFile (std::string filepath);

            // loads a model from a file using the format described above
            static BasicLayerList* loadFromFile (std::string filepath);
      };
   }
}


#endif