#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>
std::mutex mux;
using namespace std;

class gameConvalidator{
  public:
    static void SingleFileConvalidator(string _Input_file,string _Output_file);
    void MultithreadFileConvalidator(string _Multi_Input_file,int n_thread,string _Output_file){
          ifstream _Multi_Input_Stream(_Multi_Input_file);
          string _Single_line;
          int i=0;
          vector<thread> ThreadVector;
          while(getline(_Multi_Input_Stream,_Single_line)){
            ThreadVector.push_back(thread(SingleFileConvalidator,_Single_line,_Output_file));
          }
          for(auto &th: ThreadVector){
            th.join();
          } 


    }



    bool FileConvalidator(ifstream &_File_stream,vector<vector<int>> &Mat){
      string _Single_line;
      int read=0,element=0,sum=0;
      size_t sz;
      while(getline(_File_stream,_Single_line)){
      read=0;
      vector<int> row;
        while(read<_Single_line.length()){
          element = (stoi(_Single_line.substr(read),&sz,10));
          if(!(element<15) && !(element>1))
            return false;
          read+=sz+1;
          row.push_back(element);
    }
        sum+=row.size();
        Mat.push_back(row);}
        if(sum==15)
          return true;
        else
          return false;
    }

bool Find_If_Solution(vector<vector<int>> &Mat){
    int i=1;
    for(auto& Vector: Mat){
      for(auto& Vector_element: Vector){
        if(!(Vector_element==i))
          return false;
        i++;
    }
  }
  return true;
  }
};

void gameConvalidator::SingleFileConvalidator(string _Input_file,string _Output_file){
      ifstream _Input_stream(_Input_file);
      ofstream _Output_stream;
      gameConvalidator *Convalidator = new gameConvalidator();
      vector<vector<int>> Mat(0,vector<int>(0,0));
      if((Convalidator->FileConvalidator(_Input_stream,Mat))){
        if(Convalidator->Find_If_Solution(Mat)){
          mux.lock();
          cout<<"Correct"<<endl;
          _Output_stream.open(_Output_file,std::ios_base::app);
          _Output_stream << "Correct"<<endl;
          mux.unlock();}  
      }else{
        mux.lock();
        _Output_stream.open(_Output_file,std::ios_base::app);
        cout<<"Not correct second part"<<endl;
        _Output_stream << "Not correct"<<endl;
        mux.unlock();
    }
}