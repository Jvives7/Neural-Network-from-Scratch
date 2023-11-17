#include <iostream>
#include <vector>

using namespace std;

class Neuron;

typedef std::vector<Neuron> Layer; //used for aliasing existing data types, user-defined data types, and pointers to a more meaningful name. 
                                    //Typedefs allow you to give descriptive names to standard data types, which can also help you self-document your code.



class Net
{
public:
// attributes of Net go here
    Net(const std::vector<unsigned> topology); 
    void feedForward(const std::vector<double>  &inputVals); // inputVals container is a vector of double type. pass the reference of input vals with&. Doesnt change anything in input vals argument so its a const.
    void backProp(const std::vector<double>  &targetVals);
    void getResults(std::vector<double>  &outputVals) const; // getResults will change the elements of the doubles. 
private:
    vector<Layer> m_layers; // m_layers[layerNum][neuronNum]
};
    // defining net consturctor 
    Net::Net(const std::vector<unsigned> topology);{
        //need to know how many layers of nn, will come from topology object
        unsigned numLayers = topology.size(); //.size member to get number of elements
        // For loop for iterating by 1 through layers until layer limit reached
        for (unsigned layerNum = 0; layerNum < num_of_layers; ++layerNum){
            // want to append a layer object.
            //create an empty layer and append that to the m_layers container
            m_layers.push_back(Layer()); // .push_back is a pre-defined function that is used to insert data or elements at the end of the vector or it pushes the element in the vector from the back

            // need an inner loop to add neurons to layers
            for(unsigned neuronNum = 0; neuronNum <= topology[layerNum];
        }
    }


// main body
int main(){
    // How many layers and how many neurons per layer in net that we want.
    // Topolgy will be a struct, class or obj type that we pass to the constructor.

    // topology will send in unsigned integers to program the layer and neurons of net
    // e.g., { 3, 2, 1 } 
    std::vector<unsigned> topology; // unisgned vector is always non-negative
    Net myNet(topology); // creates object myNet of Net class and passes the constructor 

    

    // During training program is interested in feedforward movement with inputs and
    // backward propagation feedback movement with target values. 

    //Feedforward job is to read values from input values and transfer to input neurons. Doesnt change anything in input vals argument so its a
    std::vector<double> inputVals; // std:: namespace qualifier so compiler can find it. vector is a variable length array, needs atleast one parameter.
    myNet.feedForward(inputVals); // access attributes and set values 

    //Back propagation and tell the neurons what the result should have been or the Target value
    std::vector<double> targetVals; // std:: namespace qualifier so compiler can find it. vector is a variable length array, needs atleast one parameter.
    myNet.backProp(targetVals);

    // get results
    std::vector<double> outputVals;
    myNet.getResults(outputVals); 
}