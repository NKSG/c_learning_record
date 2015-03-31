boolean[] sieveO fEratosthenes(int max){
    boolean[] flags = new boolean[max+1];
    int count = 0;

    init(flags);
    int prime = 2;

    while(prime <= max){
        crossOff(flags, prime);
        prime = getNextPrime(flags, prime);
        if(prime >= flags.length){
            break;
        }
    }
    return flags;
}
void crossOff(boolean[] flags, int prime){
    for(int i=prime*prime; i<flags.length();i+=prime){
        flags[i] = false;
    }
}
int getNextPrime(flags, prime){
    int next = prime+1;
    while(next<flags.length && !flags[next]){
        next++;
    }
    return next;
}
