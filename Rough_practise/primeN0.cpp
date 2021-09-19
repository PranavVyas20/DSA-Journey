#include <iostream>
using namespace std;

int main() {
int a = 2;
int b = 15;
int i = a;


for (i; i <= b; i++){
    int j = 2;
    for (j; j < i; j++){
        if ( (i % j) == 0){
            break; 
        }     
    }
    if (j == i){
      cout << i << " is prime " << endl;    
    }


}

}
#include <iostream>
using namespace std;

int main() {
	int a,b;
	cin>>a>>b;
	int i;
	int n = a;

	for(n; n<=b; n++){
	  int i = 2;
	    for( i; i<n; i++){
	        if(n%i==0){
	            break;
	        
	    }
	}if(i==n){
	    cout<<n<<endl;
	}
}
	return 0;
}
