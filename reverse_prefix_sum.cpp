#include <iostream>

int main(){
	int t;
	std::cin>>t;
	while(t--){
		int n;
		std::cin>>n;
		int s[10];
		for(int i=0;i<n;i++){
			std::cin>>s[i];
		}
		int a[10];
		for(int i=0;i<n;i++){
			int temp = s[i];
			for(int j=0;j<i;j++){
				temp = temp - a[j];
			}
			a[i] = temp;
		}
		for(int i=0;i<n;i++){
			std::cout<<a[i]<<" ";
		}
		std::cout<<"\n";
	}
}