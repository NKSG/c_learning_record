int trap(int a[], int n){
    stack<pair<int,int> > s;
    int water = 0;

    for(int i=0; i<n; ++i){
        int height = 0;
        while(!s.empty()){
            int bar = s.top().first;
            int pos = s.top().second;
            water += (min(bar,a[i])-height)*(i-pos-1);
            height = bar;

            if(a[i]<bar)
                break;
            else
                s.pop();
        }
        s.push(make_pair(a[i],i));
    }
    return water;
}
