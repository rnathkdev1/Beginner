clear;
clc
n1 = llnode(1);
addnode(n1,13);
addnode(n1,14);
addnode(n1,15);
%display(n1);
deletenode(n1);
display(n1);
deletefrompos(2,n1);
display(n1);