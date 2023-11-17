#include <iostream>
#include <vector>

using namespace std;

// Things to do to improve code

// 1. make a Connection class 29:00 min







struct Connection
{
    double weight; 
    double deltaWeight;
};



class Neuron {}; // incomplete forward reference for typedef Layer to work

typedef vector<Neuron> Layer; // used for aliasing existing data types, user-defined data types, and pointers to a more meaningful name.
                              // Typedefs allow you to give descriptive names to standard data types, which can also help you self-document your code.
// ******************************* class Neuron *************************



class Neuron
{

public:
 Neuron(unsigned numOutputs); // class will at least have a constructor
private:
    
    double outputVal; // output values of neuron
    vector<Connection> outputWeights; // connection is structured with both weight and the change in weight deltaWeight defined in struct Connection. 


}

Neuron::Neuron(unsigned numOutputs)
{
    for (unsigned c = 0; c < numOutputs; +++C){
        m_outputWeights.push_back(Connection()); // .push_back adds a new element at the end of the vector, after its current last element.
        m_outputWeights.back().weight = randomWeight(); // set weight inside of connection
    }
}

// ******************************* class neuralNet **********************
class neuralNet
{
public: 
    // functions of class neuralNet go here
    neuralNet(const vector<unsigned> &topology);
    void feedForward(const vector<double> &inputVals) {}; // inputVals container is a vector of double type. pass the reference of input vals with&. Doesnt change anything in input vals argument so its a const.
    void backProp(const std::vector<double> &targetVals) {};
    void getResults(std::vector<double> &outputVals) const {}; // getResults will change the elements of the doubles.

private: 
    // Data members go here
    // Vectors are sequence containers representing arrays that can change in size.
    vector<Layer> m_layers; // m_layers[layerNum][neuronNum]
};

    // neuralNet constructor definition
    neuralNet::neuralNet(const vector<unsigned> &topology)
    {
        // need to know how many layers of nn, will come from topology object
        unsigned numLayers = topology.size(); //.size member to get number of elements
        // For loop for iterating by 1 through layers until layer limit reached
        for (unsigned layerNum = 0; layerNum < numLayers; ++layerNum)
        {
            // want to append a layer object.
            // create an empty layer and append that to the m_layers container
            m_layers.push_back(Layer()); // .push_back is a pre-defined function that is used to insert data or elements at the end of the vector or it pushes the element in the vector from the back
            unsigned numOutputs = layerNum == topology.size() - 1 ? 0 : topology[layerNum + 1];
            // need an inner loop to add neurons to layers
            for (unsigned neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum)
            {
                // .back gives the last element in the container
                m_layers.back().push_back(Neuron(numOutputs));
                cout << "Made a Neuron" << endl;
            }
        }
    };

int main()
{
    // How many layers and how many neurons per layer in net that we want.
    // Topolgy will be a struct, class or obj type that we pass to the constructor.

    // topology will send in unsigned integers to program the layer and neurons of net
    // e.g., { 3, 2, 1 }
    std::vector<unsigned> topology; // unisgned vector is always non-negative
    topology.push_back(3);
    topology.push_back(2);
    topology.push_back(1);
    neuralNet myNet(topology); // creates object myNet of neuralNet class and passes the constructor

    // During training program is interested in feedforward movement with inputs and
    // backward propagation feedback movement with target values.

    // Feedforward job is to read values from input values and transfer to input neurons. Doesnt change anything in input vals argument so its a
    std::vector<double> inputVals; // std:: namespace qualifier so compiler can find it. vector is a variable length array, needs atleast one parameter.
    myNet.feedForward(inputVals);  // access attributes and set values

    // Back propagation and tell the neurons what the result should have been or the Target value
    vector<double> targetVals; // std:: namespace qualifier so compiler can find it. vector is a variable length array, needs atleast one parameter.
    myNet.backProp(targetVals);

    // get results
    vector<double> outputVals;
    myNet.getResults(outputVals);
}