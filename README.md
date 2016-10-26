#Features :

X : Todo
O : Done
F : Need Fix
I : Impossible

prototype : - X : blabla (username)

##Line Edition

###Mandatory

- O : Show prompt (qdequele)
- O : add one char (qdequele)
- O : del one char (qdequele)
- O : move to left (qdequele)
- O : move to right (qdequele)
- O : History (eebersol)
- O : Copy/Past/Cut (eebersol)
- O : move word left alt+left (qdequele)
- O : move word right alt+right (qdequele)
- O : move start fn+left | home (qdequele)
- O : move end fn+right | end (qdequele)
- O : move up alt+up (qdequele)
- O : move down alt+down (qdequele)
- F : quotes " ' ` () (eebersol + qdequele)
- 0 : Good implementation of tab or spaces (qdequele)

###Bonus

- O : history search builtins history | ctrl+R (eebersol)
- I : History reduce with content already write (qdequele) ! trop dure, il faut avoir un "shadow line"
- X : autocomplete (qdequele)
- O : Move max top (qdequele)
- O : Move max bottom (qdequele)
- O : Operator || and && (qdequele)

##Command execution

###Mandatory

- O : Line separator ; (qdequele)
- O : pipes | (eebersol)
- O : redirect  < >> > (eebersol)
- O : file descriptor agregator 2>&- (eebersol)
- O : Catch execution return number $? (qdequele)
- O : Logic operation || && (qdequele)

###Bonus

- O : heredoc << (eebersol)
- F : inhibiteurs """ (double quote), "’" (simple quote) et "\" (backslash) (eebersol)
- F : catch last exit code in history (qdequele)
- O : local varaibles unset export $ (qdequele)
- X : Job controls job / fg / bg / & ()
- I : Shell script ()

##Builtins

###Mandatory

- O : cd (qdequele)
- O : echo (eebersol)
- O : exit (qdequele)
- O : env (qdequele)
- O : setenv (qdequele)
- O : unsetenv (qdequele)

###Bonus

- O : History (eebersol)
- X : Read (qdequele)

#Liste des bugs :

- Executer une ligne de commande avec des tabs dedans puis executer ue ligne de commande quelconque == segfault;
- home ne vas pas à la bonne destination la premiere fois
-multi-ligne sur paste.
- pb builtin_cd ne marche pas

