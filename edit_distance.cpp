
#include "edit_distance.h"
int EditDistance::getEditDistance(const string&text,const string& pattern)
{
    int n = (int)pattern.size() ;
    int m = (int) text.size() ;

    int D[n+1][m+1];

    /* boundary conditions */
    for(int i=0; i<=m; i++)
        D[0][i] = i;
    for(int i=0; i<=n; i++)
        D[i][0] = i;

    /* solving the problem in bottom-up method */
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            //D[i][j] = min(D[i-1][j-1] +mathCost(pattern[i-1],text[j-1]), D[i-1][j]+1 );
            D[i][j] = min(D[i-1][j-1] + (pattern[i-1]==text[j-1]? 0 :1) , D[i-1][j]+1 );
            D[i][j] = min (D[i][j] , D[i][j-1] + 1 );
            /* check for trasposition */
            if( i >1 && j >1 && text[j-1]==pattern[i-2] && pattern[i-1]==text[j-2])
                D[i][j] = min(D[i][j] , D[i-2][j-2] + (pattern[i-1]==text[j-1]? 0 : 1));
       //     cout <<D[i][j]<<endl;

        }
    return D[n][m];
}
