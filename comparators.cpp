#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "comparators.h"
#include "sort.h"
#include "swap.h"
#include "input_output.h"

int StrCmp(const void* s1, const void* s2)
{
    const struct line* S1 = (const struct line*)s1;
    const struct line* S2 = (const struct line*)s2;
    return strcmp(S1->str, S2->str);
}


int RevStrCmp(const void* s1, const void* s2)
{
    const struct line* S1 = (const struct line*)s1;
    const struct line* S2 = (const struct line*)s2;

    int l1 = S1->len;
    int l2 = S2->len;

    int i1 = 1, i2 = 1, ans = 0;
    while(l1 - i1 >= 0 && l2 - i2 >= 0)
    {
        int b1 = IsLitter(&S1->str[l1 - i1]);
        int b2 = IsLitter(&S2->str[l2 - i2]);

        if(b1 && b2)
        {
            ans = S1->str[l1 - i1] - S2->str[l2 - i2];
            if(ans != 0) return ans;
            i1++;
            i2++;
        }
        else
        {
            if(!b1) i1++;
            if(!b2) i2++;
        }
    }
    return 0;
}

int IsLitter(char* symb)
{
    int sm = (int)*symb;
    if(sm < 65 || (sm > 90 && sm < 97) || sm > 122)
        return 0;
    return 1;
}
