#include<iostream>//used for input output
#include<fstream>//used for file handling
#include<string>//used for string
#include<cstdio>//used for remove
#include<direct.h>//used for mkdir,etc
#include<filesystem>//used for directory_iterator,renomve,etc
using namespace std;
 bool done=false;
void copyFiles(string path1,string path2,string name1,string name2){//function to copy file from one directory to another
    string Sourcepath=path1+"//"+name1;
    string targetpath=path2+"//"+name2;
    fstream file1;
    fstream file2;
    file1.open(Sourcepath,ios::in|ios::app);
    file2.open(targetpath,ios::out|ios::in|ios::app);
    string line;
    while(getline(file1,line)){
        file2<<line<<"\n";
       
    }
    done=true;
    file1.close();
    file2.close();
}

void moveFiles(string path1,string path2,string name1,string name2){//function to move file from one directory to another
    string Sourcepath=path1+"//"+name1;
    string targetpath=path2+"//"+name2;
    fstream file1;
    fstream file2;
    file1.open(Sourcepath,ios::in|ios::app);
    file2.open(targetpath,ios::out|ios::in|ios::app);
    string line;
    while(getline(file1,line)){
        file2<<line<<"\n";
    }
    done=true;
    file1.close();
   remove(Sourcepath.c_str());//cstr converts string to char array 
}

void creatingDirectory(string path,string name){//function to create directory
  string path1=path+"//"+name;
  if(mkdir(path1.c_str())==0){
      cout<<"Directory created successfully "<<endl;
  }
  else{
      cout<<"Error in creating directory "<<endl;
  }
   
}

void viewFile(string path1,string name){//function to view file
    string path=path1+"//"+name;
    fstream file;
    file.open(path,ios::in);
    string line;
    while(getline(file,line)){
        cout<<line<<endl;
    }
    done=true;
    file.close();

}
void append(string path1,string name,string data){//function to append data to file
    string path=path1+"//"+name;
    fstream file;
    file.open(path,ios::out|ios::app);
    file<<data<<endl;
    file.close();
done=true;
}
void listDirectory(string path){//function to list all files and directories in current directory
    for(auto& p:filesystem::directory_iterator(path)){
        cout<<p<<endl;
    }
    done=true;
}
void deleteFile_directry(string path,string name){//function to delete file or directory
    string path1=path+"//"+name;
    if(!remove(path1.c_str())){//remove() function returns 0 if file is deleted successfully
        cout<<"File deleted successfully!!!"<<endl;
    }
    else{
        cout<<"Error in deleting file!!!"<<endl;
    }
}

int main() {
    
    cout<<"**********Welcome to file manager by Rashid Hussain**********"<<endl;
    cout<<"**********Here is list of commands you can use and user Guide**********"<<endl;
    cout<<"1-ls: list all files and directories in current directory"<<endl;
    cout<<"2-mkdir: create new directory"<<endl;
    cout<<"3-cp: copy file from one directory to another"<<endl;
    cout<<"4-mv: move file from one directory to another"<<endl;
    cout<<"5-cat: view file"<<endl;
    cout<<"6-echo: append data to file"<<endl;
    cout<<"7-cd: change directory"<<endl;
    cout<<"8-rm: delete file or directory"<<endl;
    cout<<"9-exit: exit from file manager"<<endl;
cout<<"*******************************************************************************************"<<endl;
    cout<<"**********How to enter path**********"<<endl;
    cout<<"Enter path in this format C://Users//Rashid Hussain//Desktop//"<<endl;
    cout<<"**********How to enter file name**********"<<endl;
    cout<<"Enter file name in this format hello.txt or hello.doc"<<endl;
    cout<<"**********How to enter directory name**********"<<endl;
    cout<<"Enter directory name in this format 'hello' "<<endl;
cout<<"*******************************************************************************************"<<endl;
string command;
    string path1, name1,name2,path2;
    string workingDirectory;
    cout<<"Enter directory path where you want to work: ";
    cin>>workingDirectory;
 


    while(true){
cout<<"Enter your command:";
    cin>>command;
    if(command=="ls"){
        listDirectory(workingDirectory);
        if(done){
            cout<<"Command executed successfully"<<endl;
        }
        else{
            cout<<"Error in executing command"<<endl;
        }
    }
    else if(command=="mkdir"){
        cout<<"Enter directry name: ";
        cin>>name1;
        creatingDirectory(workingDirectory,name1);

    }
else if(command=="cp"){

        cout<<"Enter file name which you want to copy(in this format hello.txt or hello.doc):"<<endl;
        cin>>name1;
         cout<<"Enter distinction path  where you want to paste file: "<<endl;
         cin>>path2;
         cout<<"Enter new file name to store data of previous copied file(in this format hello.txt or hello.doc):"<<endl;
        cin>>name2;
        copyFiles(workingDirectory,path2,name1,name2);
          if(done){
            cout<<"Command executed successfully"<<endl;
        }
        else{
            cout<<"Error in executing command"<<endl;
        }
    }
    else if(command=="mv"){
        cout<<"Enter file name which you want to move/cut(in this format hello.txt or hello.doc):"<<endl;
        cin>>name1;
         cout<<"Enter distinction path  where you want to paste file: "<<endl;
         cin>>path2;
        moveFiles(workingDirectory,path2,name1,name1);
            if(done){
                cout<<"Command executed successfully"<<endl;
            }
            else{
                cout<<"Error in executing command"<<endl;
            }
    }
    else if(command=="cat"){

        cout<<"Enter name of file to display(in this format hello.txt or hello.doc):"<<endl;
        cin>>name1;
        viewFile(workingDirectory,name1);
            if(done){
                cout<<"Command executed successfully"<<endl;
            }
            else{
                cout<<"Error in executing command"<<endl;
            }
    }
    else if(command=="echo"){
        string data;
        cout<<"Enter name of file to append data(in this format hello.txt or hello.doc):"<<endl;
        cin>>name1;
        cout<<"Enter data you want to append to "<<name1<<" file"<<endl;
        cin.ignore();
        getline(cin,data);
        
        append(workingDirectory,name1,data);
            if(done){
                cout<<"Command executed successfully"<<endl;
            }
            else{
                cout<<"Error in executing command"<<endl;
            }
    }
    else if(command=="cd"){
        cout<<"Enter path of directory where you want to go: "<<endl;
        cin>>path1;
        workingDirectory=path1;
    }
    else if(command=="rm"){
        cout<<"Enter name of file or directory you want to delete: "<<endl;
        cin>>name1;
        deleteFile_directry(workingDirectory,name1);
}
    
else if(command=="exit"){
    break;
    
    } 
    else{
        cout<<"Invalid command"<<endl;
    }  }
    
  return 0;
}