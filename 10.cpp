#include <iostream>
#include <fstream>

using namespace std;string capitalizeCharStr(string &givenString)
{
    for (int i = 0; i < givenString.length(); i++)
    {
        if (i == 0 || i == givenString.length() - 1)
        {
            givenString[i] = toupper(givenString[i]);
        }
        else if (givenString[i] == ' ')
        {
            givenString[i - 1] = toupper(givenString[i - 1]);
            givenString[i + 1] = toupper(givenString[i + 1]);
        }
        else if(givenString[i]=='\n'){
            givenString[i - 1] = toupper(givenString[i - 1]);
            givenString[i + 1] = toupper(givenString[i + 1]);
        }
        

        
    }
    return givenString;
}int main(int argc,char*argv[])
{    
    string s;
        string tot;

    if (argc > 1) {
        cout << "argv[1] = " << argv[1] << endl; 
    } else {
        cout << "No file name entered. Exiting...";
        return -1;
    }
    ifstream in(argv[1]);
     //open the file
    
    if (in.is_open() && in.good()) {

        while(!in.eof()){
            getline(in,s);
            tot+=s+ "\n";
        }
        cout<< tot;
         
        
        in.close();
    } else {
        cout << "Failed to open file..";
    }
       
        ofstream out;
        out.open(argv[1]);
    cout<< capitalizeCharStr(tot);
        out << tot;
        out.close();

}
