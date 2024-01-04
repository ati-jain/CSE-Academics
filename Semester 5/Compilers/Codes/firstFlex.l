%{
    int chars = 0;
%}
%%
"r"[a-s]	{chars++;}
.|\n     	{chars++;}
<<EOF>>     {return chars;}
%%
