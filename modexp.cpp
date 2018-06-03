long long int m=1000000000+7;
long long int modexp(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    else if(b%2==0)
    {
        long long int c=modexp(a,b/2);
        return((c*c)%m);
    }
    else
    {
        return(((a%m)*modexp(a,b-1))%m);
    }
}
