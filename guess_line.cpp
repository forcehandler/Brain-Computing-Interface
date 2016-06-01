#include <iostream>
#include <cstdlib>
using namespace std;
 
class Perceptron
{
    public:
    int n;
    float weights[100000], hi,lo;
    void assign()
    {
 
        srand(time(NULL));
        float g = this->lo + static_cast <float> (rand()) / static_cast <float> (RAND_MAX/((this->hi)-(this->lo)));
        for(int i=0;i<n;i++)
        {
           // this->weights[i] = this->lo + static_cast <float> (rand()) / static_cast <float> (RAND_MAX/((this->hi)-(this->lo)));
           this->weights[i]=g;
        }
        
        cout<<"Assigning\n";
        
        for(int i=0;i<n;i++)
        {
            cout<<this->weights[i]<<endl;
        }
        //cout<< this->hi << "     "<<this->lo << endl;
    }
 
    float feedforward(int input[], int n)
    {
        float sum;
        for(int i = 0; i < n ;i++)
        {
            sum += this->weights[i]*input[i];
        }
        
         /*cout<<"For Calculating \n";
        
        for(int i=0;i<n;i++)
        {
            cout<<this->weights[i]<<endl;
        }*/
        
        return sum;
    }
    int activate(float sum)
    {
        if(sum > 0)
        return 1;
        else
        return -1;
    }
    
    int calc(int in[], int d)
{
    float m=2,c=0;
    if(in[1]-m*in[0]-c>0)
    return -1;
    else if(in[1]-m*in[0]-c<0)
    return 1;
    else
    return -1;
}
void train(int in[], int a)
{
    float lc=0.1;
    
        int guess = this->activate(this->feedforward(in, a));
        int desired = calc(in, a);
        float error = desired - guess;
        cout<<"guess "<<guess<<" desired "<<desired<<endl;
 
        for(int j = 0 ; j < a; j++)
        {
            this->weights[j] += lc*error*in[j];
        }
        
        
        for(int j = 0 ; j < a; j++)
        {
            cout<<this->weights[j]<<endl;
        }
}
 
};
 

 
/*int** input(int a, int b)
{
    int in[a][b];  //C++ does not advocate to return the address of a local variable to outside of the function so you would have to define the local variable as static variable.
    for(int i = 0; i < a; i++)
    {
        for(int j = 0 ; j < 3; j++)
        {
            if (j==2)
            in[a][b]=1;
            else
            cin >> in[a][b];
        }
    }
}*/
 
int main()
{
    Perceptron p;
    p.n=3;
    p.hi = 1;
    p.lo = -1;
    p.assign();
    /*int** in=input(5,3);
    train(in, 5);*/
 
    /*int input[p.n] = {1,5,1};
    float out = p.feedforward(input, p.n);
    cout << "out  "<< out << endl;
    cout<<p.activate(out)<<endl;*/
    //int tr[3]={77,2,1};
    //p.train(tr,3);
    for(int i = 0; i < 10000; i++)
    {
        int y = (rand()%1000)-500;
        int z = (rand()%1000)-500;
        int v[3] = {y,z,1};
        p.train(v,3);
    }
    
    
}
