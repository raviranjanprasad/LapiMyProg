#include<iostream>
#include<cctype>
#include<cstring>
#include<string>

using namespace std;
bool isalphaNum(const string &data){
     string::size_type nSize = data.size();
     for(string::size_type i = 0; i < nSize; i++) {
        if (isalnum(data[i])){
            cout<<data[i]<<endl;
            return true;
        }
        else{
            cout<<data[i]<<endl;
            continue;
        }
    }
    return false;
}

int main(int argc, char *argv[]){
	
      string udid;
      udid="##";
      if(isalphaNum(udid))
	 cout<<udid<<"First UDID alphanumeric\n";
      else
	 cout<<udid<<"not UDID alphanumeric\n";

      udid +="test 123\n"; 
      if(isalphaNum(udid))
         cout<<udid<<"UDID alphanumeric\n";

      udid = "::::::###$$$@@@@";
      if(isalphaNum(udid))
         cout<<udid<<"UDID alphanumeric\n";

}
