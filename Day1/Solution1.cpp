#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,x;
    vector<int> a;
    cout<<"Enter length of input list";
    cin>>n;
    cout<<"Enter list";
    for(int i=0;i<n;i++) {
        cin>>x;
        a.push_back(x);
    }
    int i=0,j=n-1;
    int ans=0;
    while(i<j){
        ans=max(ans,min(a[i],a[j])*(j-i));
        if(a[i]>a[j]) j--;
        else i++;
    }
    cout<<ans;
    return 1;
}
