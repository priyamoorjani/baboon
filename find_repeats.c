#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SEQNAME_MAX BUFSIZ

int main(int argc,char** argv)
    {
    int c;
    int pos=1;
    char name[SEQNAME_MAX];
    name[0]=0;

    for(;;)
            {
            switch((c=fgetc(stdin)))
                {
        case EOF: return EXIT_SUCCESS;
        case '>':
            {
            int space=0;
            int name_length=0;
            name[0]=0;
            pos=1;
            while((c=fgetc(stdin))!=EOF && c!='\n')
                {    
                if(space) continue;
                if(isspace(c)) { space=1; continue;}
                name[name_length++]=c;
                }
            name[name_length]=0;
            break;
            }
        case '\n':case '\r':case ' ':break;
        case 'a': 
            {
                printf("%s\t%d\t%d\n",name,pos-1, pos);
            ++pos;
            break;
            } 
	case 't': 
           {
                printf("%s\t%d\t%d\n",name,pos-1, pos);
            ++pos;
            break;
            }
	case 'g':
	   {
	    	printf("%s\t%d\t%d\n",name,pos-1, pos);
            ++pos;
            break;
            }
	case 'c':
	   {
	    	printf("%s\t%d\t%d\n",name,pos-1, pos);
            ++pos;
            break;
            } 
        default: ++pos;break;
                }
        }
    return EXIT_SUCCESS;
    }

