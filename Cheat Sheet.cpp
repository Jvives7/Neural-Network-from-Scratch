    /*
    
    Net(const vector<unsigned> &topology)
    {
        // need to know how many layers of nn, will come from topology object
        unsigned numLayers = topology.size(); //.size member to get number of elements
        // For loop for iterating by 1 through layers until layer limit reached
        for (unsigned layerNum = 0; layerNum < numLayers; ++layerNum)
        {
            // want to append a layer object.
            // create an empty layer and append that to the m_layers container
            m_layers.push_back(Layer()); // .push_back is a pre-defined function that is used to insert data or elements at the end of the vector or it pushes the element in the vector from the back

            // need an inner loop to add neurons to layers
            for (unsigned neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum)
            {
                // .back gives the last element in the container
                m_layers.back().push_back(Neuron());
                cout << "Made a Neuron" << endl;
            }
        }
    }




  /////////////// CHEAT SHEET ////////////////////////////

  class ClassName
  {
    Access Modifier:        // can be private, public or protected

    Data member;            //  Variables to be used 

    Member functions;       //  Methodsa to access data members 

  };    //Class name ends with a semicolon




 // public: can be accessed anywhere in the program 
 // private: can be accessed only by functions inside the class

 //






































    */